import FWCore.ParameterSet.Config as cms


#print "Running on data or mc"

HLTLIST = cms.VPSet(
    #MuTau SingleL1
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sSingleMu22erL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24LooseChargedIsoPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackLooseChargedIsoAgainstMuon", "hltOverlapFilterIsoMu24LooseChargedIsoPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau20_TightID_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sSingleMu22erL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24LooseChargedIsoTightOOSCPhotonsPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackLooseChargedIsoTightOOSCPhotonsAgainstMuon", "hltOverlapFilterIsoMu24LooseChargedIsoTightOOSCPhotonsPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sSingleMu22erL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackMediumChargedIsoAgainstMuon", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau20_TightID_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sSingleMu22erL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoTightOOSCPhotonsPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackMediumChargedIsoTightOOSCPhotonsAgainstMuon", "hltOverlapFilterIsoMu24MediumChargedIsoTightOOSCPhotonsPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sSingleMu22erL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackTightChargedIsoAgainstMuon", "hltOverlapFilterIsoMu24TightChargedIsoPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau20_TightID_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sSingleMu22erL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoTightOOSCPhotonsPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackTightChargedIsoTightOOSCPhotonsAgainstMuon", "hltOverlapFilterIsoMu24TightChargedIsoTightOOSCPhotonsPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),

    #MuTau CrossL1

    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24LooseChargedIsoPFTau35MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau35TrackPt1LooseChargedIsolationL1HLTMatchedReg", "hltOverlapFilterIsoMu24LooseChargedIsoPFTau35MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_LooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24LooseChargedIsoAndTightOOSCPhotonsPFTau35MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau35TrackPt1LooseChargedIsolationAndTightOOSCPhotonsL1HLTMatchedReg", "hltOverlapFilterIsoMu24LooseChargedIsoAndTightOOSCPhotonsPFTau35MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau35MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau35TrackPt1MediumChargedIsolationL1HLTMatchedReg", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau35MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoAndTightOOSCPhotonsPFTau35MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau35TrackPt1MediumChargedIsolationAndTightOOSCPhotonsL1HLTMatchedReg", "hltOverlapFilterIsoMu24MediumChargedIsoAndTightOOSCPhotonsPFTau35MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoPFTau35MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau35TrackPt1TightChargedIsolationL1HLTMatchedReg", "hltOverlapFilterIsoMu24TightChargedIsoPFTau35MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoAndTightOOSCPhotonsPFTau35MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau35TrackPt1TightChargedIsolationAndTightOOSCPhotonsL1HLTMatchedReg", "hltOverlapFilterIsoMu24TightChargedIsoAndTightOOSCPhotonsPFTau35MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),

    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1MediumChargedIsolationL1HLTMatchedReg", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1MediumChargedIsolationAndTightOOSCPhotonsL1HLTMatchedReg", "hltOverlapFilterIsoMu24MediumChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1TightChargedIsolationL1HLTMatchedReg", "hltOverlapFilterIsoMu24TightChargedIsoPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1TightChargedIsolationAndTightOOSCPhotonsL1HLTMatchedReg", "hltOverlapFilterIsoMu24TightChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),



    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu22erIsoTau40erL1f0L2f10QL3f20QL3trkIsoFiltered0p07"),
        path2 = cms.vstring ("hltSelectedPFTau50MediumChargedIsolationL1HLTMatchedMu22IsoTau40"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),

    cms.PSet (
        HLT = cms.string("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu18erTau24erIorMu20erTau24erL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu20LooseChargedIsoPFTau27L1Seeded"),
        path2 = cms.vstring ("hltSelectedPFTau27LooseChargedIsolationAgainstMuonL1HLTMatched", "hltOverlapFilterIsoMu20LooseChargedIsoPFTau27L1Seeded"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu18erTau24erIorMu20erTau24erL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu20MediumChargedIsoPFTau27L1Seeded"),
        path2 = cms.vstring ("hltSelectedPFTau27MediumChargedIsolationAgainstMuonL1HLTMatched", "hltOverlapFilterIsoMu20MediumChargedIsoPFTau27L1Seeded"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu18erTau24erIorMu20erTau24erL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu20TightChargedIsoPFTau27L1Seeded"),
        path2 = cms.vstring ("hltSelectedPFTau27TightChargedIsolationAgainstMuonL1HLTMatched", "hltOverlapFilterIsoMu20TightChargedIsoPFTau27L1Seeded"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu20_eta2p1_LooseChargedIsoPFTau27_eta2p1_TightID_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu18erTau24erIorMu20erTau24erL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu20LooseChargedIsoTightOOSCPhotonsPFTau27L1Seeded"),
        path2 = cms.vstring ("hltSelectedPFTau27LooseChargedIsolationTightOOSCPhotonsAgainstMuonL1HLTMatched", "hltOverlapFilterIsoMu20LooseChargedIsoTightOOSCPhotonsPFTau27L1Seeded"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu20_eta2p1_MediumChargedIsoPFTau27_eta2p1_TightID_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu18erTau24erIorMu20erTau24erL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu20MediumChargedIsoTightOOSCPhotonsPFTau27L1Seeded"),
        path2 = cms.vstring ("hltSelectedPFTau27MediumChargedIsolationTightOOSCPhotonsAgainstMuonL1HLTMatched", "hltOverlapFilterIsoMu20MediumChargedIsoTightOOSCPhotonsPFTau27L1Seeded"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu20_eta2p1_TightChargedIsoPFTau27_eta2p1_TightID_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu18erTau24erIorMu20erTau24erL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu20TightChargedIsoTightOOSCPhotonsPFTau27L1Seeded"),
        path2 = cms.vstring ("hltSelectedPFTau27TightChargedIsolationTightOOSCPhotonsAgainstMuonL1HLTMatched", "hltOverlapFilterIsoMu20TightChargedIsoTightOOSCPhotonsPFTau27L1Seeded"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),

    #ETau CrossL1
    cms.PSet (
        HLT = cms.string("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_CrossL1_v"),
        path1 = cms.vstring ("hltEle24erWPTightGsfTrackIsoFilterForTau", "hltOverlapFilterIsoEle24WPTightGsfLooseIsoPFTau30"),
        path2 = cms.vstring ("hltSelectedPFTau30LooseChargedIsolationL1HLTMatched", "hltOverlapFilterIsoEle24WPTightGsfLooseIsoPFTau30"),
        leg1 = cms.int32(11),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_CrossL1_v"),
        path1 = cms.vstring ("hltEle24erWPTightGsfTrackIsoFilterForTau", "hltOverlapFilterIsoEle24WPTightGsfMediumIsoPFTau30"),
        path2 = cms.vstring ("hltSelectedPFTau30MediumChargedIsolationL1HLTMatched", "hltOverlapFilterIsoEle24WPTightGsfMediumIsoPFTau30"),
        leg1 = cms.int32(11),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_CrossL1_v"),
        path1 = cms.vstring ("hltEle24erWPTightGsfTrackIsoFilterForTau", "hltOverlapFilterIsoEle24WPTightGsfTightIsoPFTau30"),
        path2 = cms.vstring ("hltSelectedPFTau30TightChargedIsolationL1HLTMatched", "hltOverlapFilterIsoEle24WPTightGsfTightIsoPFTau30"),
        leg1 = cms.int32(11),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_Ele24_eta2p1_WPTight_Gsf_LooseChargedIsoPFTau30_eta2p1_TightID_CrossL1_v"),
        path1 = cms.vstring ("hltEle24erWPTightGsfTrackIsoFilterForTau", "hltOverlapFilterIsoEle24WPTightGsfLooseIsoTightOOSCPhotonsPFTau30"),
        path2 = cms.vstring ("hltSelectedPFTau30LooseChargedIsolationTightOOSCPhotonsL1HLTMatched", "hltOverlapFilterIsoEle24WPTightGsfLooseIsoTightOOSCPhotonsPFTau30"),
        leg1 = cms.int32(11),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_Ele24_eta2p1_WPTight_Gsf_MediumChargedIsoPFTau30_eta2p1_TightID_CrossL1_v"),
        path1 = cms.vstring ("hltEle24erWPTightGsfTrackIsoFilterForTau", "hltOverlapFilterIsoEle24WPTightGsfMediumIsoTightOOSCPhotonsPFTau30"),
        path2 = cms.vstring ("hltSelectedPFTau30MediumChargedIsolationTightOOSCPhotonsL1HLTMatched", "hltOverlapFilterIsoEle24WPTightGsfMediumIsoTightOOSCPhotonsPFTau30"),
        leg1 = cms.int32(11),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_Ele24_eta2p1_WPTight_Gsf_TightChargedIsoPFTau30_eta2p1_TightID_CrossL1_v"),
        path1 = cms.vstring ("hltEle24erWPTightGsfTrackIsoFilterForTau", "hltOverlapFilterIsoEle24WPTightGsfTightIsoTightOOSCPhotonsPFTau30"),
        path2 = cms.vstring ("hltSelectedPFTau30TightChargedIsolationTightOOSCPhotonsL1HLTMatched", "hltOverlapFilterIsoEle24WPTightGsfTightIsoTightOOSCPhotonsPFTau30"),
        leg1 = cms.int32(11),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleLooseChargedIsoPFTau35_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau35TrackPt1LooseChargedIsolationDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau35TrackPt1LooseChargedIsolationDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleLooseChargedIsoPFTau40_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau40TrackPt1LooseChargedIsolationDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau40TrackPt1LooseChargedIsolationDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleMediumChargedIsoPFTau35_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau35TrackPt1MediumChargedIsolationDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau35TrackPt1MediumChargedIsolationDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleMediumChargedIsoPFTau40_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau40TrackPt1MediumChargedIsolationDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau40TrackPt1MediumChargedIsolationDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleTightChargedIsoPFTau35_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau35TrackPt1TightChargedIsolationDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau35TrackPt1TightChargedIsolationDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleTightChargedIsoPFTau40_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau40TrackPt1TightChargedIsolationDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau40TrackPt1TightChargedIsolationDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleLooseChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau35TrackPt1LooseChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau35TrackPt1LooseChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleLooseChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau40TrackPt1LooseChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau40TrackPt1LooseChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleMediumChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau35TrackPt1MediumChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau35TrackPt1MediumChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleMediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau40TrackPt1MediumChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau40TrackPt1MediumChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleTightChargedIsoPFTau35_Trk1_TightID_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau35TrackPt1TightChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau35TrackPt1TIghtChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_DoubleTightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_v"),
        path1 = cms.vstring ("hltDoublePFTau40TrackPt1TightChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        path2 = cms.vstring ("hltDoublePFTau40TrackPt1TIghtChargedIsolationAndTightOOSCPhotonsDz02Reg"),
        leg1 = cms.int32(15),
        leg2 = cms.int32(15)
    ),

    #Tau + MET
    cms.PSet (
        HLT = cms.string("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET90_v"),
        path1 = cms.vstring ("hltSelectedPFTau50MediumChargedIsolationL1HLTMatched"),
        path2 = cms.vstring (""),
        leg1 = cms.int32(15),
        leg2 = cms.int32(999)
    ),
    cms.PSet (
        HLT = cms.string("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_MET100_v"),
        path1 = cms.vstring ("hltSelectedPFTau50MediumChargedIsolationL1HLTMatched"),
        path2 = cms.vstring (""),
        leg1 = cms.int32(15),
        leg2 = cms.int32(999)
    ),
    cms.PSet (
        HLT = cms.string("HLT_MediumChargedIsoPFTau50_Trk30_eta2p1_1pr_v"),
        path1 = cms.vstring ("hltSelectedPFTau50MediumChargedIsolationL1HLTMatched"),
        path2 = cms.vstring (""),
        leg1 = cms.int32(15),
        leg2 = cms.int32(999)
    ),

    #SingleTau
    cms.PSet (
        HLT = cms.string("HLT_MediumChargedIsoPFTau100HighPtRelaxedIso_Trk50_eta2p1_1pr_v"),
        path1 = cms.vstring ("hltSelectedPFTau180MediumChargedIsolationL1HLTMatched1Prong"),
        path2 = cms.vstring (""),
        leg1 = cms.int32(15),
        leg2 = cms.int32(999)
    ),
    cms.PSet (
        HLT = cms.string("HLT_MediumChargedIsoPFTau180HighPtRelaxedIso_Trk50_eta2p1_v"),
        path1 = cms.vstring ("hltSelectedPFTau180MediumChargedIsolationL1HLTMatched1Prong"),
        path2 = cms.vstring (""),
        leg1 = cms.int32(15),
        leg2 = cms.int32(999)
    ),

    cms.PSet (
        HLT = cms.string("HLT_IsoMu27_v"),
        path1 = cms.vstring (""),
        path2 = cms.vstring (""),
        leg1 = cms.int32(13),
        leg2 = cms.int32(-1)
    ),

    cms.PSet (
        HLT = cms.string("HLT_IsoMu27_LooseChargedIsoPFTau20_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu22Or25L1f0L2f10QL3f27QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu27LooseChargedIsoPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackLooseChargedIsoAgainstMuon", "hltOverlapFilterIsoMu27LooseChargedIsoPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),

    cms.PSet (
        HLT = cms.string("HLT_IsoMu27_MediumChargedIsoPFTau20_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu22Or25L1f0L2f10QL3f27QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu27MediumChargedIsoPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackMediumChargedIsoAgainstMuon", "hltOverlapFilterIsoMu27MediumChargedIsoPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),

    cms.PSet (
        HLT = cms.string("HLT_IsoMu27_TightChargedIsoPFTau20_SingleL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sMu22Or25L1f0L2f10QL3f27QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu27TightChargedIsoPFTau20"),
        path2 = cms.vstring ("hltPFTau20TrackTightChargedIsoAgainstMuon", "hltOverlapFilterIsoMu27TightChargedIsoPFTau20"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),

    cms.PSet (
        HLT = cms.string("HLT_VBF_DoubleLooseChargedIsoPFTau20_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring (""),
        path2 = cms.vstring (""),
        leg1 = cms.int32(-1),
        leg2 = cms.int32(-1)
    ),

    cms.PSet (
        HLT = cms.string("HLT_VBF_DoubleMediumChargedIsoPFTau20_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring (""),
        path2 = cms.vstring (""),
        leg1 = cms.int32(-1),
        leg2 = cms.int32(-1)
    ),

    cms.PSet (
        HLT = cms.string("HLT_VBF_DoubleTightChargedIsoPFTau20_Trk1_eta2p1_Reg_v"),
        path1 = cms.vstring (""),
        path2 = cms.vstring (""),
        leg1 = cms.int32(-1),
        leg2 = cms.int32(-1)
    ),

        #Mu+Tau40
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f20QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1MediumChargedIsolationL1HLTMatchedReg", "hltOverlapFilterIsoMu24MediumChargedIsoPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_MediumChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24MediumChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1MediumChargedIsolationAndTightOOSCPhotonsL1HLTMatchedReg", "hltOverlapFilterIsoMu24MediumChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau35_Trk1_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1TightChargedIsolationL1HLTMatchedReg", "hltOverlapFilterIsoMu24TightChargedIsoPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),
    cms.PSet (
        HLT = cms.string("HLT_IsoMu24_eta2p1_TightChargedIsoPFTau40_Trk1_TightID_eta2p1_Reg_CrossL1_v"),
        path1 = cms.vstring ("hltL3crIsoL1sBigOrMuXXerIsoTauYYerL1f0L2f10QL3f24QL3trkIsoFiltered0p07", "hltOverlapFilterIsoMu24TightChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        path2 = cms.vstring ("hltSelectedPFTau40TrackPt1TightChargedIsolationAndTightOOSCPhotonsL1HLTMatchedReg", "hltOverlapFilterIsoMu24TightChargedIsoAndTightOOSCPhotonsPFTau40MonitoringReg"),
        leg1 = cms.int32(13),
        leg2 = cms.int32(15)
    ),


)





ZeroBias = cms.EDAnalyzer("ZeroBias",
    treeName = cms.string("ZeroBias"),
    L1Tau = cms.InputTag("caloStage2Digis", "Tau"),
    L1EmuTau = cms.InputTag("simCaloStage2Digis", "MP"),
    l1tJetCollection = cms.InputTag("caloStage2Digis","Jet"),
    l1tEmuJetCollection = cms.InputTag("simCaloStage2Digis","MP"),
    L1SumCollection = cms.InputTag("caloStage2Digis","EtSum"),
    L1EmuSumCollection = cms.InputTag("simCaloStage2Digis","MP"),
    L1EG = cms.InputTag("caloStage2Digis", "EGamma"),
    L1EmuEG = cms.InputTag("simCaloStage2Digis", "MP"),
    L1Mu = cms.InputTag("hltGtStage2Digis"),
    L1EmuMu = cms.InputTag("simGtStage2Digis"),
    triggerList = HLTLIST,
    #triggerSet = cms.InputTag("slimmedPatTrigger"),
    triggerSet = cms.InputTag("patTriggerUnpacker"),
    triggerResultsLabel = cms.InputTag("TriggerResults", "", "HLT"),
    L2CaloJet_L1TauSeeded_Collection = cms.InputTag("hltL2TauJetsL1IsoTauSeeded", "", "MYHLT"),
    L2CaloJet_ForIsoPix_Collection = cms.InputTag("hltL2TausForPixelIsolation", "", "MYHLT"),
    L2CaloJet_ForIsoPix_IsoCollection = cms.InputTag("hltL2TauPixelIsoTagProducer", "", "MYHLT"),                      
    L2CaloJet_IsoPix_Collection = cms.InputTag("hltL2TauJetsIso", "", "MYHLT"),
    PixelTrackCollection = cms.InputTag("hltPixelTracksMergedRegForTau", "", "MYHLT"),
    MergedTrackCollection = cms.InputTag("hltMergedTracksTauReg", "", "MYHLT"),
    PFRegCandCollection = cms.InputTag("hltParticleFlowReg", "", "MYHLT"),
    AK4PFRegJetCollection = cms.InputTag("hltAK4PFJetsReg", "", "MYHLT"),
    PFTauSansRefRegCollection = cms.InputTag("hltPFTausSansRefReg", "", "MYHLT"),
    PFJetRegionCollection = cms.InputTag("hltTauPFJets08RegionReg", "jets", "MYHLT"),
    PFJetChargedHadronAssociation = cms.InputTag("hltTauPFJetsRecoTauChargedHadronsReg", "", "MYHLT"),
    JetPiZeroAssociation = cms.InputTag("hltPFTauPiZerosReg", "", "MYHLT")
)


NtupleZeroBiasSeq = cms.Sequence(
    ZeroBias
)





patTriggerUnpacker = cms.EDProducer("PATTriggerObjectStandAloneUnpacker",
                                    patTriggerObjectsStandAlone = cms.InputTag("slimmedPatTrigger"),
                                    triggerResults = cms.InputTag('TriggerResults', '', "HLT"),
                                    unpackFilterLabels = cms.bool(True)
                                    )

patTriggerUnpackerSeq = cms.Sequence(
    patTriggerUnpacker
)
