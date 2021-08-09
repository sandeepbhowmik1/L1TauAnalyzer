import FWCore.ParameterSet.VarParsing as VarParsing
import FWCore.PythonUtilities.LumiList as LumiList
import FWCore.ParameterSet.Config as cms
process = cms.Process("L1TauAnalyzer")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")


process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
         '/store/mc/Run3Winter21DRMiniAOD/VBFHToTauTau_M125_TuneCP5_14TeV-powheg-pythia8/MINIAODSIM/FlatPU30to80FEVT_112X_mcRun3_2021_realistic_v16-v1/270000/27bd7637-5f76-4051-a38a-a5a0bfdf51b2.root'
    ),
)

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '112X_mcRun3_2021_realistic_v15', '')

# Sequence, Path and EndPath definitions
process.analysisSequence = cms.Sequence()

process.load('L1TauAnalyzer.L1TauAnalyzer.MCanalysis_noTagAndProbe_cff')
process.analysisSequence += process.TAndPseq
process.analysisSequence += process.NtupleSeq

process.analysis_step = cms.Path(process.analysisSequence)



options = VarParsing.VarParsing ('analysis')
# output file
options.outputFile = 'RootTree_noTagAndProbe_MC_MiniAOD_VBFHToTauTau_20210727.root'

# Adding ntuplizer 
process.TFileService=cms.Service('TFileService',fileName=cms.string(options.outputFile))



# Silence output
process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)
