# TEMPLATE used for automatic script submission of multiple datasets

from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'VBFHToTauTau_Run3Winter21DRMiniAOD_20210727'
config.General.workArea = 'crablog_mc'
config.General.transferOutputs = True
config.General.transferLogs    = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '../test/test_noTagAndProbe_MC_MiniAOD.py'
config.JobType.allowUndistributedCMSSW = True
#config.JobType.numCores = 2
#config.JobType.maxMemoryMB = 4000

config.section_("Data")
config.Data.inputDataset = '/VBFHToTauTau_M125_TuneCP5_14TeV-powheg-pythia8/Run3Winter21DRMiniAOD-FlatPU30to80FEVT_112X_mcRun3_2021_realistic_v16-v1/MINIAODSIM'
#config.Data.secondaryInputDataset = '/VBFHToTauTau_M125_TuneCP5_14TeV-powheg-pythia8/Run3Winter21DRMiniAOD-FlatPU30to80FEVT_112X_mcRun3_2021_realistic_v16-v1/GEN-SIM-DIGI-RAW'
#Data.useParent = True
config.Data.inputDBS = 'global'
#config.Data.splitting = 'Automatic'
#config.Data.splitting = 'FileBased'
#config.Data.unitsPerJob = 1000
config.Data.splitting        = 'EventAwareLumiBased'
config.Data.unitsPerJob      = 100
config.Data.totalUnits = -1 #number of event
config.Data.outLFNDirBase = '/store/user/sbhowmik'
config.Data.publication = False
config.Data.outputDatasetTag = 'VBFHToTauTau_Run3Winter21DRMiniAOD_20210727'

config.section_("Site")
config.Site.storageSite = 'T2_EE_Estonia'
#config.Site.whitelist = ["T2_EE_Estonia"]

