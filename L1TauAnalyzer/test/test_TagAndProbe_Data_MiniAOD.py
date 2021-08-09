import FWCore.ParameterSet.VarParsing as VarParsing
import FWCore.PythonUtilities.LumiList as LumiList
import FWCore.ParameterSet.Config as cms
from Configuration.Eras.Era_Run2_2018_cff import Run2_2018
process = cms.Process("L1TauAnalyzer", Run2_2018)

useCustomHLT = False
useMassCuts = False

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
         #'/store/mc/Run3Winter21DRMiniAOD/VBFHToTauTau_M125_TuneCP5_14TeV-powheg-pythia8/MINIAODSIM/FlatPU30to80FEVT_112X_mcRun3_2021_realistic_v16-v1/270000/27bd7637-5f76-4051-a38a-a5a0bfdf51b2.root'
        '/store/data/Run2018D/SingleMuon/MINIAOD/PromptReco-v2/000/321/732/00000/1C2ED445-B1AA-E811-87FF-FA163EA7E2FA.root'
    ),
)

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '112X_dataRun2_v7', '')

# Sequence, Path and EndPath definitions
process.analysisSequence = cms.Sequence()

process.load("Configuration.StandardSequences.GeometryRecoDB_cff")

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
process.load("RecoEgamma.ElectronIdentification.ElectronMVAValueMapProducer_cfi")
dataFormat = DataFormat.MiniAOD
switchOnVIDElectronIdProducer(process, dataFormat)
process.load("RecoEgamma.ElectronIdentification.egmGsfElectronIDs_cfi")
process.egmGsfElectronIDs.physicsObjectSrc = cms.InputTag('slimmedElectrons')
from PhysicsTools.SelectorUtils.centralIDRegistry import central_id_registry
process.egmGsfElectronIDSequence = cms.Sequence(process.egmGsfElectronIDs)
my_id_modules =[
'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV60_cff',
'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_GeneralPurpose_V1_cff',
'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_HZZ_V1_cff',
'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Fall17_iso_V1_cff'
]
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)
egmMod = 'egmGsfElectronIDs'
mvaMod = 'electronMVAValueMapProducer'
mvaModHelper = 'electronMVAVariableHelper'
setattr(process,egmMod,process.egmGsfElectronIDs.clone())
setattr(process,mvaMod,process.electronMVAValueMapProducer.clone())
#setattr(process,mvaModHelper,process.electronMVAVariableHelper.clone())
#process.electrons = cms.Sequence(getattr(process,mvaModHelper)*getattr(process,mvaMod)*getattr(process,egmMod))
process.electrons = cms.Sequence(getattr(process,mvaMod)*getattr(process,egmMod))

process.analysisSequence += process.electrons

process.load('L1TauAnalyzer.L1TauAnalyzer.DataAnalysis_TagAndProbe_cff')
if useCustomHLT:
    process.hltFilter.TriggerResultsTag = cms.InputTag("TriggerResults","","MYHLT")
    process.Ntuplizer.triggerSet = cms.InputTag("selectedPatTriggerCustom", "", "MYHLT")
    process.Ntuplizer.triggerResultsLabel = cms.InputTag("TriggerResults", "", "MYHLT")
    process.Ntuplizer.L2CaloJet_ForIsoPix_Collection = cms.InputTag("hltL2TausForPixelIsolation", "", "MYHLT")
    process.Ntuplizer.L2CaloJet_ForIsoPix_IsoCollection = cms.InputTag("hltL2TauPixelIsoTagProducer", "", "MYHLT")

process.TagAndProbe.useMassCuts = cms.bool(useMassCuts)

process.analysisSequence += process.TAndPseq
process.analysisSequence += process.NtupleSeq

process.analysis_step = cms.Path(process.analysisSequence)



options = VarParsing.VarParsing ('analysis')
# output file
options.outputFile = 'RootTree_TagAndProbe_Data_MiniAOD_Run2018D_20210727.root'

# Adding ntuplizer 
process.TFileService=cms.Service('TFileService',fileName=cms.string(options.outputFile))



# Silence output
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)
