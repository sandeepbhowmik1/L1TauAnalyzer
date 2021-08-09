#ifndef NTUPLIZER_H
#define NTUPLIZER_H

#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <TNtuple.h>
#include <TString.h>
#include <bitset>

#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Common/interface/TriggerResultsByName.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <FWCore/Framework/interface/Frameworkfwd.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/Utilities/interface/InputTag.h>
#include <DataFormats/PatCandidates/interface/Muon.h>
#include <DataFormats/PatCandidates/interface/Tau.h>
#include <DataFormats/PatCandidates/interface/MET.h>
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "HLTrigger/HLTcore/interface/HLTPrescaleProvider.h"
#include "DataFormats/L1Trigger/interface/Tau.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include <DataFormats/PatCandidates/interface/GenericParticle.h>
#include "DataFormats/Common/interface/TriggerResults.h"

#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

#include "tParameterSet.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"



//Set this variable to decide the number of triggers that you want to check simultaneously
#define NUMBER_OF_MAXIMUM_TRIGGERS 64


/*
██████  ███████  ██████ ██       █████  ██████   █████  ████████ ██  ██████  ███    ██
██   ██ ██      ██      ██      ██   ██ ██   ██ ██   ██    ██    ██ ██    ██ ████   ██
██   ██ █████   ██      ██      ███████ ██████  ███████    ██    ██ ██    ██ ██ ██  ██
██   ██ ██      ██      ██      ██   ██ ██   ██ ██   ██    ██    ██ ██    ██ ██  ██ ██
██████  ███████  ██████ ███████ ██   ██ ██   ██ ██   ██    ██    ██  ██████  ██   ████
*/

class Ntuplizer : public edm::EDAnalyzer {
    public:
        /// Constructor
        explicit Ntuplizer(const edm::ParameterSet&);
        /// Destructor
        virtual ~Ntuplizer();

    private:
        //----edm control---
        virtual void beginJob() ;
        virtual void beginRun(edm::Run const&, edm::EventSetup const&);
        virtual void analyze(const edm::Event&, const edm::EventSetup&);
        virtual void endJob();
        virtual void endRun(edm::Run const&, edm::EventSetup const&);
        void Initialize();
        bool hasFilters(const pat::TriggerObjectStandAlone&  obj , const std::vector<std::string>& filtersToLookFor);
        int GenIndex(const pat::TauRef& tau, const edm::View<pat::GenericParticle>* genparts);
  float ComputeMT (math::XYZTLorentzVector visP4, const pat::MET& met);

        bool _isMC;

        TTree *_tree;
        TTree *_triggerNamesTree;
        std::string _treeName;
        // -------------------------------------
        // variables to be filled in output tree
        ULong64_t       _indexevents;
        Int_t           _runNumber;
        Int_t           _lumi;
        Int_t           _PS_column;

        float           _MC_weight;

        unsigned long _tauTriggerBits;
        float _tauPt;
        float _tauEta;
        float _tauPhi;
        int _tauDM;
        float _mT;
        float _mVis;
        int _tau_genindex;        
  
        bool _byLooseCombinedIsolationDeltaBetaCorr3Hits;
        bool _byMediumCombinedIsolationDeltaBetaCorr3Hits;
        bool _byTightCombinedIsolationDeltaBetaCorr3Hits;
        bool _byVLooseIsolationMVArun2v1DBoldDMwLT;
        bool _byLooseIsolationMVArun2v1DBoldDMwLT;
        bool _byMediumIsolationMVArun2v1DBoldDMwLT;
        bool _byTightIsolationMVArun2v1DBoldDMwLT;
        bool _byVTightIsolationMVArun2v1DBoldDMwLT;
        bool _byVLooseIsolationMVArun2v1DBnewDMwLT;
        bool _byLooseIsolationMVArun2v1DBnewDMwLT;
        bool _byMediumIsolationMVArun2v1DBnewDMwLT;
        bool _byTightIsolationMVArun2v1DBnewDMwLT;
        bool _byVTightIsolationMVArun2v1DBnewDMwLT;       
        bool _byLooseIsolationMVArun2v1DBdR03oldDMwLT;
        bool _byMediumIsolationMVArun2v1DBdR03oldDMwLT;
        bool _byTightIsolationMVArun2v1DBdR03oldDMwLT;
        bool _byVTightIsolationMVArun2v1DBdR03oldDMwLT;
          
        bool _againstMuonLoose3;
        bool _againstMuonTight3;
        bool _againstElectronVLooseMVA6;
        bool _againstElectronLooseMVA6;
        bool _againstElectronMediumMVA6;
        bool _againstElectronTightMVA6;
        bool _againstElectronVTightMVA6;

        float _hltPt;
        float _hltEta;
        float _hltPhi;
        float _hltL2CaloJetPt;
        float _hltL2CaloJetEta;
        float _hltL2CaloJetPhi;
        float _hltL2CaloJetIso;
        float _hltL2CaloJetIsoPixPt;
        float _hltL2CaloJetIsoPixEta;
        float _hltL2CaloJetIsoPixPhi;
        float _hltPFTauTrackPt;
        float _hltPFTauTrackEta;
        float _hltPFTauTrackPhi;
        float _hltPFTauTrackRegPt;
        float _hltPFTauTrackRegEta;
        float _hltPFTauTrackRegPhi;
        float _hltPFTau35TrackPt1RegPt;
        float _hltPFTau35TrackPt1RegEta;
        float _hltPFTau35TrackPt1RegPhi;

        int _l1tQual;
        float _l1tPt;
        float _l1tEta;
        float _l1tPhi;
        int _l1tIso;
        int _l1tEmuQual;
        float _l1tEmuPt;
        float _l1tEmuEta;
        float _l1tEmuPhi;
        int _l1tEmuIso;
        int _l1tEmuNTT;
        int _l1tEmuHasEM;
        int _l1tEmuIsMerged;
        int _l1tEmuTowerIEta;
        int _l1tEmuTowerIPhi;
        int _l1tEmuRawEt;
        int _l1tEmuIsoEt;
        Bool_t _hasTriggerMuonType;
        Bool_t _hasTriggerTauType;
        Bool_t _isMatched;
        Bool_t _isOS;
        int _foundJet;
        float _muonPt;
        float _muonEta;
        float _muonPhi;
        float _MET;
        int _Nvtx;
        float _nTruePU;
		
        edm::EDGetTokenT<GenEventInfoProduct> _genTag;
        edm::EDGetTokenT<edm::View<pat::GenericParticle> > _genPartTag;

        edm::EDGetTokenT<pat::MuonRefVector>  _muonsTag;
        edm::EDGetTokenT<pat::TauRefVector>   _tauTag;
        edm::EDGetTokenT<pat::METCollection>  _metTag;
        edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> _triggerObjects;
        edm::EDGetTokenT<edm::TriggerResults> _triggerBits;
        edm::EDGetTokenT<l1t::TauBxCollection> _L1TauTag  ;
        edm::EDGetTokenT<l1t::TauBxCollection> _L1EmuTauTag  ;
        edm::EDGetTokenT<std::vector<reco::Vertex>> _VtxTag;
        edm::EDGetTokenT<std::vector<PileupSummaryInfo>> _puTag;
        edm::EDGetTokenT<reco::CaloJetCollection> _hltL2CaloJet_ForIsoPix_Tag;
        edm::EDGetTokenT<reco::JetTagCollection> _hltL2CaloJet_ForIsoPix_IsoTag;
  //unsigned int stageL1Trigger_;
        //!Contains the parameters
        tVParameterSet _parameters;
        tVParameterSet _parameters_Tag;

        edm::InputTag _processName;
        //! Maximum
        std::bitset<NUMBER_OF_MAXIMUM_TRIGGERS> _tauTriggerBitSet;



        HLTConfigProvider _hltConfig;
        HLTPrescaleProvider* _hltPrescale;


};

/*
██ ███    ███ ██████  ██      ███████ ███    ███ ███████ ███    ██ ████████  █████  ████████ ██  ██████  ███    ██
██ ████  ████ ██   ██ ██      ██      ████  ████ ██      ████   ██    ██    ██   ██    ██    ██ ██    ██ ████   ██
██ ██ ████ ██ ██████  ██      █████   ██ ████ ██ █████   ██ ██  ██    ██    ███████    ██    ██ ██    ██ ██ ██  ██
██ ██  ██  ██ ██      ██      ██      ██  ██  ██ ██      ██  ██ ██    ██    ██   ██    ██    ██ ██    ██ ██  ██ ██
██ ██      ██ ██      ███████ ███████ ██      ██ ███████ ██   ████    ██    ██   ██    ██    ██  ██████  ██   ████
*/

// ----Constructor and Destructor -----
Ntuplizer::Ntuplizer(const edm::ParameterSet& iConfig) :
_genTag         (consumes<GenEventInfoProduct>                    (iConfig.getParameter<edm::InputTag>("genCollection"))),
_genPartTag     (consumes<edm::View<pat::GenericParticle>>        (iConfig.getParameter<edm::InputTag>("genPartCollection"))),
_muonsTag       (consumes<pat::MuonRefVector>                     (iConfig.getParameter<edm::InputTag>("muons"))),
_tauTag         (consumes<pat::TauRefVector>                      (iConfig.getParameter<edm::InputTag>("taus"))),
_metTag         (consumes<pat::METCollection>                     (iConfig.getParameter<edm::InputTag>("met"))),
_triggerObjects (consumes<pat::TriggerObjectStandAloneCollection> (iConfig.getParameter<edm::InputTag>("triggerSet"))),
_triggerBits    (consumes<edm::TriggerResults>                    (iConfig.getParameter<edm::InputTag>("triggerResultsLabel"))),
_L1TauTag       (consumes<l1t::TauBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1Tau"))),
_L1EmuTauTag    (consumes<l1t::TauBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1EmuTau"))),
_VtxTag         (consumes<std::vector<reco::Vertex>>              (iConfig.getParameter<edm::InputTag>("Vertexes"))),
_puTag			(consumes<std::vector<PileupSummaryInfo>>		  (iConfig.getParameter<edm::InputTag>("puInfo"))),
_hltL2CaloJet_ForIsoPix_Tag(consumes<reco::CaloJetCollection>     (iConfig.getParameter<edm::InputTag>("L2CaloJet_ForIsoPix_Collection"))),
_hltL2CaloJet_ForIsoPix_IsoTag(consumes<reco::JetTagCollection>   (iConfig.getParameter<edm::InputTag>("L2CaloJet_ForIsoPix_IsoCollection")))
{

     _isMC = iConfig.getParameter<bool>("isMC");
     //stageL1Trigger_ = iConfig.getParameter<unsigned int>("stageL1Trigger");

    _hltPrescale = new HLTPrescaleProvider(iConfig,consumesCollector(),*this);
    
    _treeName = iConfig.getParameter<std::string>("treeName");
    _processName = iConfig.getParameter<edm::InputTag>("triggerResultsLabel");

    TString triggerName;
    edm::Service<TFileService> fs;
    _triggerNamesTree = fs -> make<TTree>("triggerNames", "triggerNames");
    _triggerNamesTree -> Branch("triggerNames",&triggerName);

    //Building the trigger arrays
    const std::vector<edm::ParameterSet>& HLTList = iConfig.getParameter <std::vector<edm::ParameterSet> > ("triggerList");
    for (const edm::ParameterSet& parameterSet : HLTList) {
        tParameterSet pSet;
        pSet.hltPath = parameterSet.getParameter<std::string>("HLT");
        triggerName = pSet.hltPath;
        pSet.hltFilters1 = parameterSet.getParameter<std::vector<std::string> >("path1");
        pSet.hltFilters2 = parameterSet.getParameter<std::vector<std::string> >("path2");
        pSet.leg1 = parameterSet.getParameter<int>("leg1");
        pSet.leg2 = parameterSet.getParameter<int>("leg2");
        _parameters.push_back(pSet);
	
        _triggerNamesTree -> Fill();
    }

    const std::vector<edm::ParameterSet>& HLTList_Tag = iConfig.getParameter <std::vector<edm::ParameterSet> > ("triggerList_tag");
    for (const edm::ParameterSet& parameterSet : HLTList_Tag) {
        tParameterSet pSet;
        pSet.hltPath = parameterSet.getParameter<std::string>("HLT");
        pSet.hltFilters1 = parameterSet.getParameter<std::vector<std::string> >("path1");
        pSet.hltFilters2 = parameterSet.getParameter<std::vector<std::string> >("path2");
        pSet.leg1 = parameterSet.getParameter<int>("leg1");
        pSet.leg2 = parameterSet.getParameter<int>("leg2");
        _parameters_Tag.push_back(pSet);
    }
    


    this -> Initialize();
    return;
}

Ntuplizer::~Ntuplizer()
{
    delete _hltPrescale;
}

void Ntuplizer::beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup)
{
    Bool_t changedConfig = false;

    if(!_hltConfig.init(iRun, iSetup, _processName.process(), changedConfig)){
        edm::LogError("HLTMatchingFilter") << "Initialization of HLTConfigProvider failed!!";
        return;
    }

    if(!_hltPrescale->init(iRun, iSetup, _processName.process(), changedConfig)){
        edm::LogError("HLTMatchingFilter") << "Initialization of HLTPrescaleProvider failed!!";
        return;
    }

    const edm::TriggerNames::Strings& triggerNames = _hltConfig.triggerNames();
    std::cout << " ===== LOOKING FOR THE PATH INDEXES =====" << std::endl;
    for (tParameterSet& parameter : _parameters){
        const std::string& hltPath = parameter.hltPath;
        bool found = false;
        for(unsigned int j=0; j < triggerNames.size(); j++)
        {
	  //std::cout << triggerNames[j] << std::endl;
            if (triggerNames[j].find(hltPath) != std::string::npos) {
                found = true;
                parameter.hltPathIndex = j;

                std::cout << "### FOUND AT INDEX #" << j << " --> " << triggerNames[j] << std::endl;
            }
        }
        if (!found) parameter.hltPathIndex = -1;
    }



    std::cout << " ===== LOOKING FOR THE PATH INDEXES FOR TAG=====" << std::endl;
    for (tParameterSet& parameter : _parameters_Tag){
        const std::string& hltPath = parameter.hltPath;
        bool found = false;
        for(unsigned int j=0; j < triggerNames.size(); j++)
        {
	  // std::cout << triggerNames[j] << std::endl;
            if (triggerNames[j].find(hltPath) != std::string::npos) {
                found = true;
                parameter.hltPathIndex = j;

                std::cout << "### FOUND AT INDEX #" << j << " --> " << triggerNames[j] << std::endl;
            }
        }
        if (!found) parameter.hltPathIndex = -1;
    }

}

void Ntuplizer::Initialize() {
    _indexevents = 0;
    _runNumber = 0;
    _lumi = 0;
    _PS_column = -1;
    
    _MC_weight = 1;
    
    _tauPt = -1.;
    _tauEta = -1.;
    _tauPhi = -1.;
    _tauDM = -1;
    _mT = -1.;
    _mVis = -1.;
    _tau_genindex = -1;
    
    _byLooseCombinedIsolationDeltaBetaCorr3Hits = 0;
    _byMediumCombinedIsolationDeltaBetaCorr3Hits = 0;
    _byTightCombinedIsolationDeltaBetaCorr3Hits = 0;
    _byVLooseIsolationMVArun2v1DBoldDMwLT = 0;
    _byLooseIsolationMVArun2v1DBoldDMwLT = 0;
    _byMediumIsolationMVArun2v1DBoldDMwLT = 0;
    _byTightIsolationMVArun2v1DBoldDMwLT = 0;
    _byVTightIsolationMVArun2v1DBoldDMwLT = 0;
    _byVLooseIsolationMVArun2v1DBnewDMwLT = 0;
    _byLooseIsolationMVArun2v1DBnewDMwLT = 0;
    _byMediumIsolationMVArun2v1DBnewDMwLT = 0;
    _byTightIsolationMVArun2v1DBnewDMwLT = 0;
    _byVTightIsolationMVArun2v1DBnewDMwLT = 0;    
    _byLooseIsolationMVArun2v1DBdR03oldDMwLT = 0;
    _byMediumIsolationMVArun2v1DBdR03oldDMwLT = 0;
    _byTightIsolationMVArun2v1DBdR03oldDMwLT = 0;
    _byVTightIsolationMVArun2v1DBdR03oldDMwLT = 0;
    
    _againstMuonLoose3 = 0;
    _againstMuonTight3 = 0;
    _againstElectronVLooseMVA6 = 0;
    _againstElectronLooseMVA6 = 0;
    _againstElectronMediumMVA6 = 0;
    _againstElectronTightMVA6 = 0;
    _againstElectronVTightMVA6 = 0;
    
    _muonPt = -1.;
    _muonEta = -1.;
    _muonPhi = -1.;
    _MET = -1.;
    _isMatched = false;
    
    _hltPt = -1;
    _hltEta = 666;
    _hltPhi = 666;
    _hltL2CaloJetPt = -1;
    _hltL2CaloJetEta = 666;
    _hltL2CaloJetPhi = 666;
    _hltL2CaloJetIso = -1;
    _hltL2CaloJetIsoPixPt = -1;
    _hltL2CaloJetIsoPixEta = 666;
    _hltL2CaloJetIsoPixPhi = 666;
    _hltPFTauTrackPt = -1;
    _hltPFTauTrackEta = 666;
    _hltPFTauTrackPhi = 666;
    _hltPFTauTrackRegPt = -1;
    _hltPFTauTrackRegEta = 666;
    _hltPFTauTrackRegPhi = 666;
    _hltPFTau35TrackPt1RegPt = -1;
    _hltPFTau35TrackPt1RegEta = 666;
    _hltPFTau35TrackPt1RegPhi = 666;
    
    _l1tPt = -1;
    _l1tEta = 666;
    _l1tPhi = 666;
    _l1tQual = -1;
    _l1tIso = -1;
    _l1tEmuPt = -1;
    _l1tEmuEta = 666;
    _l1tEmuPhi = 666;
    _l1tEmuQual = -1;
    _l1tEmuIso = -1;
    _l1tEmuNTT = -1;
    _l1tEmuHasEM = -1;
    _l1tEmuIsMerged = -1;
    _l1tEmuTowerIEta = -1;
    _l1tEmuTowerIPhi = -1;
    _l1tEmuRawEt = -1;
    _l1tEmuIsoEt = -1;
    _foundJet = 0;
}


void Ntuplizer::beginJob()
{
    edm::Service<TFileService> fs;
    _tree = fs -> make<TTree>(this -> _treeName.c_str(), this -> _treeName.c_str());

    //Branches
    _tree -> Branch("EventNumber",&_indexevents,"EventNumber/l");
    _tree -> Branch("RunNumber",&_runNumber,"RunNumber/I");
    _tree -> Branch("lumi",&_lumi,"lumi/I");
    _tree -> Branch("PS_column",&_PS_column,"PS_column/I");
    
    _tree -> Branch("MC_weight",&_MC_weight,"MC_weight/F");
    
    _tree -> Branch("tauTriggerBits", &_tauTriggerBits, "tauTriggerBits/l");
    _tree -> Branch("tauPt",  &_tauPt,  "tauPt/F");
    _tree -> Branch("tauEta", &_tauEta, "tauEta/F");
    _tree -> Branch("tauPhi", &_tauPhi, "tauPhi/F");
    _tree -> Branch("tauDM", &_tauDM, "tauDM/I");
    _tree -> Branch("mT", &_mT, "mT/F");
    _tree -> Branch("mVis", &_mVis, "mVis/F");
    _tree -> Branch("tau_genindex", &_tau_genindex, "tau_genindex/I");
    
    _tree -> Branch("byLooseCombinedIsolationDeltaBetaCorr3Hits", &_byLooseCombinedIsolationDeltaBetaCorr3Hits, "byLooseCombinedIsolationDeltaBetaCorr3Hits/O");
    _tree -> Branch("byMediumCombinedIsolationDeltaBetaCorr3Hits", &_byMediumCombinedIsolationDeltaBetaCorr3Hits, "byMediumCombinedIsolationDeltaBetaCorr3Hits/O");
    _tree -> Branch("byTightCombinedIsolationDeltaBetaCorr3Hits", &_byTightCombinedIsolationDeltaBetaCorr3Hits, "byTightCombinedIsolationDeltaBetaCorr3Hits/O");
    _tree -> Branch("byVLooseIsolationMVArun2v1DBoldDMwLT", &_byVLooseIsolationMVArun2v1DBoldDMwLT, "byVLooseIsolationMVArun2v1DBoldDMwLT/O");
    _tree -> Branch("byLooseIsolationMVArun2v1DBoldDMwLT", &_byLooseIsolationMVArun2v1DBoldDMwLT, "byLooseIsolationMVArun2v1DBoldDMwLT/O");
    _tree -> Branch("byMediumIsolationMVArun2v1DBoldDMwLT", &_byMediumIsolationMVArun2v1DBoldDMwLT, "byMediumIsolationMVArun2v1DBoldDMwLT/O");
    _tree -> Branch("byTightIsolationMVArun2v1DBoldDMwLT", &_byTightIsolationMVArun2v1DBoldDMwLT, "byTightIsolationMVArun2v1DBoldDMwLT/O");
    _tree -> Branch("byVTightIsolationMVArun2v1DBoldDMwLT", &_byVTightIsolationMVArun2v1DBoldDMwLT, "byVTightIsolationMVArun2v1DBoldDMwLT/O");
    _tree -> Branch("byVLooseIsolationMVArun2v1DBnewDMwLT", &_byVLooseIsolationMVArun2v1DBnewDMwLT, "byVLooseIsolationMVArun2v1DBnewDMwLT/O");
    _tree -> Branch("byLooseIsolationMVArun2v1DBnewDMwLT", &_byLooseIsolationMVArun2v1DBnewDMwLT, "byLooseIsolationMVArun2v1DBnewDMwLT/O");
    _tree -> Branch("byMediumIsolationMVArun2v1DBnewDMwLT", &_byMediumIsolationMVArun2v1DBnewDMwLT, "byMediumIsolationMVArun2v1DBnewDMwLT/O");
    _tree -> Branch("byTightIsolationMVArun2v1DBnewDMwLT", &_byTightIsolationMVArun2v1DBnewDMwLT, "byTightIsolationMVArun2v1DBnewDMwLT/O");
    _tree -> Branch("byVTightIsolationMVArun2v1DBnewDMwLT", &_byVTightIsolationMVArun2v1DBnewDMwLT, "byVTightIsolationMVArun2v1DBnewDMwLT/O");    
    _tree -> Branch("byLooseIsolationMVArun2v1DBdR03oldDMwLT", &_byLooseIsolationMVArun2v1DBdR03oldDMwLT, "byLooseIsolationMVArun2v1DBdR03oldDMwLT/O");
    _tree -> Branch("byMediumIsolationMVArun2v1DBdR03oldDMwLT", &_byMediumIsolationMVArun2v1DBdR03oldDMwLT, "byMediumIsolationMVArun2v1DBdR03oldDMwLT/O");
    _tree -> Branch("byTightIsolationMVArun2v1DBdR03oldDMwLT", &_byTightIsolationMVArun2v1DBdR03oldDMwLT, "byTightIsolationMVArun2v1DBdR03oldDMwLT/O");
    _tree -> Branch("byVTightIsolationMVArun2v1DBdR03oldDMwLT", &_byVTightIsolationMVArun2v1DBdR03oldDMwLT, "byVTightIsolationMVArun2v1DBdR03oldDMwLT/O");
    
    
    _tree -> Branch("againstMuonLoose3", &_againstMuonLoose3, "againstMuonLoose3/O");;
    _tree -> Branch("againstMuonTight3", &_againstMuonTight3, "againstMuonTight3/O");
    _tree -> Branch("againstElectronVLooseMVA6", &_againstElectronVLooseMVA6, "againstElectronVLooseMVA6/O");
    _tree -> Branch("againstElectronLooseMVA6", &_againstElectronLooseMVA6, "againstElectronLooseMVA6/O");
    _tree -> Branch("againstElectronMediumMVA6", &_againstElectronMediumMVA6, "againstElectronMediumMVA6/O");
    _tree -> Branch("againstElectronTightMVA6", &_againstElectronTightMVA6, "againstElectronTightMVA6/O");
    _tree -> Branch("againstElectronVTightMVA6", &_againstElectronVTightMVA6, "againstElectronVTightMVA6/O");
    
    _tree -> Branch("muonPt",  &_muonPt,  "muonPt/F");
    _tree -> Branch("muonEta", &_muonEta, "muonEta/F");
    _tree -> Branch("muonPhi", &_muonPhi, "muonPhi/F");
    
    _tree -> Branch("MET", &_MET, "MET/F");

    _tree -> Branch("hltPt",  &_hltPt,  "hltPt/F");
    _tree -> Branch("hltEta", &_hltEta, "hltEta/F");
    _tree -> Branch("hltPhi", &_hltPhi, "hltPhi/F");
    
    _tree -> Branch("hltL2CaloJetPt",  &_hltL2CaloJetPt,  "hltL2CaloJetPt/F");
    _tree -> Branch("hltL2CaloJetEta", &_hltL2CaloJetEta, "hltL2CaloJetEta/F");
    _tree -> Branch("hltL2CaloJetPhi", &_hltL2CaloJetPhi, "hltL2CaloJetPhi/F");
    _tree -> Branch("hltL2CaloJetIso", &_hltL2CaloJetIso, "hltL2CaloJetIso/F");
    _tree -> Branch("hltL2CaloJetIsoPixPt",  &_hltL2CaloJetIsoPixPt,  "hltL2CaloJetIsoPixPt/F");
    _tree -> Branch("hltL2CaloJetIsoPixEta", &_hltL2CaloJetIsoPixEta, "hltL2CaloJetIsoPixEta/F");
    _tree -> Branch("hltL2CaloJetIsoPixPhi", &_hltL2CaloJetIsoPixPhi, "hltL2CaloJetIsoPixPhi/F");
    
    _tree -> Branch("hltPFTauTrackPt",  &_hltPFTauTrackPt,  "hltPFTauTrackPt/F");
    _tree -> Branch("hltPFTauTrackEta", &_hltPFTauTrackEta, "hltPFTauTrackEta/F");;
    _tree -> Branch("hltPFTauTrackPhi", &_hltPFTauTrackPhi, "hltPFTauTrackPhi/F");
    _tree -> Branch("hltPFTauTrackRegPt",  &_hltPFTauTrackRegPt,  "hltPFTauTrackRegPt/F");
    _tree -> Branch("hltPFTauTrackRegEta", &_hltPFTauTrackRegEta, "hltPFTauTrackRegEta/F");;
    _tree -> Branch("hltPFTauTrackRegPhi", &_hltPFTauTrackRegPhi, "hltPFTauTrackRegPhi/F");
    _tree -> Branch("hltPFTau35TrackPt1RegPt",  &_hltPFTau35TrackPt1RegPt,  "hltPFTau35TrackPt1RegPt/F");
    _tree -> Branch("hltPFTau35TrackPt1RegEta", &_hltPFTau35TrackPt1RegEta, "hltPFTau35TrackPt1RegEta/F");;
    _tree -> Branch("hltPFTau35TrackPt1RegPhi", &_hltPFTau35TrackPt1RegPhi, "hltPFTau35TrackPt1RegPhi/F");
    
    
    _tree -> Branch("l1tPt",  &_l1tPt,  "l1tPt/F");
    _tree -> Branch("l1tEta", &_l1tEta, "l1tEta/F");
    _tree -> Branch("l1tPhi", &_l1tPhi, "l1tPhi/F");
    _tree -> Branch("l1tQual", &_l1tQual, "l1tQual/I");
    _tree -> Branch("l1tIso", &_l1tIso, "l1tIso/I");
    _tree -> Branch("l1tEmuPt",  &_l1tEmuPt,  "l1tEmuPt/F");
    _tree -> Branch("l1tEmuEta", &_l1tEmuEta, "l1tEmuEta/F");
    _tree -> Branch("l1tEmuPhi", &_l1tEmuPhi, "l1tEmuPhi/F");
    _tree -> Branch("l1tEmuQual", &_l1tEmuQual, "l1tEmuQual/I");
    _tree -> Branch("l1tEmuIso", &_l1tEmuIso, "l1tEmuIso/I");
    _tree -> Branch("l1tEmuNTT", &_l1tEmuNTT, "l1tEmuNTT/I");
    _tree -> Branch("l1tEmuHasEM", &_l1tEmuHasEM, "l1tEmuHasEM/I");
    _tree -> Branch("l1tEmuIsMerged", &_l1tEmuIsMerged, "l1tEmuIsMerged/I");
    _tree -> Branch("l1tEmuTowerIEta", &_l1tEmuTowerIEta, "l1tEmuTowerIEta/I");
    _tree -> Branch("l1tEmuTowerIPhi", &_l1tEmuTowerIPhi, "l1tEmuTowerIPhi/I");
    _tree -> Branch("l1tEmuRawEt", &_l1tEmuRawEt, "l1tEmuRawEt/I");
    _tree -> Branch("l1tEmuIsoEt", &_l1tEmuIsoEt, "l1tEmuIsoEt/I");
    
    
    _tree -> Branch("hasTriggerMuonType", &_hasTriggerMuonType, "hasTriggerMuonType/O");
    _tree -> Branch("hasTriggerTauType", &_hasTriggerTauType, "hasTriggerTauType/O");
    _tree -> Branch("isMatched", &_isMatched, "isMatched/O");
    _tree -> Branch("isOS", &_isOS, "isOS/O");
    _tree -> Branch("foundJet", &_foundJet, "foundJet/I");
    _tree -> Branch("Nvtx", &_Nvtx, "Nvtx/I");
    _tree -> Branch("nTruePU", &_nTruePU, "nTruePU/F");

    return;
}


void Ntuplizer::endJob()
{
    return;
}


void Ntuplizer::endRun(edm::Run const& iRun, edm::EventSetup const& iSetup)
{
    return;
}


void Ntuplizer::analyze(const edm::Event& iEvent, const edm::EventSetup& eSetup)
{
    this -> Initialize();

    _indexevents = iEvent.id().event();
    _runNumber = iEvent.id().run();
    _lumi = iEvent.luminosityBlock();
    if(!_isMC)      
      _PS_column = _hltPrescale->prescaleSet(iEvent,eSetup);

    edm::Handle<GenEventInfoProduct> genEvt;
    try {iEvent.getByToken(_genTag, genEvt);}  catch (...) {;}
    if(genEvt.isValid()) _MC_weight = genEvt->weight();

    // search for the tag in the event
    edm::Handle<edm::View<pat::GenericParticle> > genPartHandle;
    edm::Handle<pat::MuonRefVector> muonHandle;
    edm::Handle<pat::TauRefVector>  tauHandle;
    edm::Handle<pat::METCollection> metHandle;
    edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;
    edm::Handle<edm::TriggerResults> triggerBits;
    edm::Handle<std::vector<reco::Vertex> >  vertexes;
   	edm::Handle<std::vector<PileupSummaryInfo>> puInfo;

    edm::Handle< reco::CaloJetCollection > L2CaloJets_ForIsoPix_Handle;
    edm::Handle< reco::JetTagCollection > L2CaloJets_ForIsoPix_IsoHandle;


    if(_isMC)
      iEvent.getByToken(_genPartTag, genPartHandle);
    iEvent.getByToken(_muonsTag, muonHandle);
    iEvent.getByToken(_tauTag,   tauHandle);
    iEvent.getByToken (_metTag, metHandle);
    iEvent.getByToken(_triggerObjects, triggerObjects);
    iEvent.getByToken(_triggerBits, triggerBits);
    iEvent.getByToken(_VtxTag,vertexes);
    iEvent.getByToken(_puTag, puInfo);
    
    try {iEvent.getByToken(_hltL2CaloJet_ForIsoPix_Tag, L2CaloJets_ForIsoPix_Handle);}  catch (...) {;}
    try {iEvent.getByToken(_hltL2CaloJet_ForIsoPix_IsoTag, L2CaloJets_ForIsoPix_IsoHandle);}  catch (...) {;}



    //! TagAndProbe on HLT taus
    const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);
    const pat::TauRef tau = (*tauHandle)[0] ;
    const pat::MuonRef muon = (*muonHandle)[0] ;
    const pat::MET& met = (*metHandle)[0];

    _MET = met.pt();
    _mT = this->ComputeMT (muon->p4(), met);

    if(muonHandle.isValid()) _isOS = (muon -> charge() / tau -> charge() < 0) ? true : false;


    _tauTriggerBitSet.reset();

    bool foundMuTrigger = false;

    for (pat::TriggerObjectStandAlone  obj : *triggerObjects)
    {

      obj.unpackPathNames(names);
      const edm::TriggerNames::Strings& triggerNames = names.triggerNames();

      if(obj.hasTriggerObjectType(trigger::TriggerMuon)){

        const float dR = deltaR (*muon, obj);
        if ( dR < 0.5 && fabs(obj.eta())<2.1 ){

	  for (const tParameterSet& parameter : _parameters_Tag)
            {
	      if ((parameter.hltPathIndex >= 0)&&(obj.hasPathName(triggerNames[parameter.hltPathIndex], true, false)))	
		foundMuTrigger = true;
	    }

	}

      }
      


        const float dR = deltaR (*tau, obj);
        if ( dR < 0.5)
        {
            _isMatched = true;
            _hasTriggerTauType = obj.hasTriggerObjectType(trigger::TriggerTau);	   
            _hasTriggerMuonType = obj.hasTriggerObjectType(trigger::TriggerMuon);

            //Looking for the path
            unsigned int x = 0;
            bool foundTrigger = false;
            for (const tParameterSet& parameter : _parameters)
            {
	      if ((parameter.hltPathIndex >= 0)&&(obj.hasPathName(triggerNames[parameter.hltPathIndex], true, false)))

                {

                    foundTrigger = true;
                    //Path found, now looking for the label 1, if present in the parameter set                    
                    //Retrieving filter list for the event

                    const std::vector<std::string>& filters = (parameter.leg1 == 15)? (parameter.hltFilters1):(parameter.hltFilters2);
                    if (this -> hasFilters(obj, filters))
                    {
                        _hltPt = obj.pt();
                        _hltEta = obj.eta();
                        _hltPhi = obj.phi();
                        _tauTriggerBitSet[x] = true;
                    }
                }
                x++;
            }
            if (foundTrigger) _foundJet++;

	    const std::vector<std::string>& L2CaloJetIsoPix_filters = {"hltL2TauIsoFilter"};
	    if (this -> hasFilters(obj, L2CaloJetIsoPix_filters) && obj.pt()>_hltL2CaloJetIsoPixPt){
	      _hltL2CaloJetIsoPixPt = obj.pt();
	      _hltL2CaloJetIsoPixEta = obj.eta();
	      _hltL2CaloJetIsoPixPhi = obj.phi();
	    }

	    const std::vector<std::string>& PFTauTrack_filters = {"hltPFTauTrack"};
	    if (this -> hasFilters(obj, PFTauTrack_filters) && obj.pt()>_hltPFTauTrackPt){
	      _hltPFTauTrackPt = obj.pt();
	      _hltPFTauTrackEta = obj.eta();
	      _hltPFTauTrackPhi = obj.phi();
	    }

	    const std::vector<std::string>& PFTauTrackReg_filters = {"hltPFTauTrackReg"};
	    if (this -> hasFilters(obj, PFTauTrackReg_filters) && obj.pt()>_hltPFTauTrackRegPt){
	      _hltPFTauTrackRegPt = obj.pt();
	      _hltPFTauTrackRegEta = obj.eta();
	      _hltPFTauTrackRegPhi = obj.phi();
	    }

	    const std::vector<std::string>& PFTau35TrackPt1Reg_filters = {"hltSinglePFTau35TrackPt1Reg"};
	    if (this -> hasFilters(obj, PFTau35TrackPt1Reg_filters) && obj.pt()>_hltPFTau35TrackPt1RegPt){
	      _hltPFTau35TrackPt1RegPt = obj.pt();
	      _hltPFTau35TrackPt1RegEta = obj.eta();
	      _hltPFTau35TrackPt1RegPhi = obj.phi();
	    }


        }
    }


    if(L2CaloJets_ForIsoPix_Handle.isValid() && L2CaloJets_ForIsoPix_IsoHandle.isValid()){

      for (auto const &  jet : *L2CaloJets_ForIsoPix_IsoHandle){
	edm::Ref<reco::CaloJetCollection> jetRef = edm::Ref<reco::CaloJetCollection>(L2CaloJets_ForIsoPix_Handle,jet.first.key());
	
	const float dR = deltaR (*tau, *(jet.first));
	
	if ( dR < 0.5 && jet.first->pt()>_hltL2CaloJetPt)
	  {
	    _hltL2CaloJetPt = jet.first->pt();
	    _hltL2CaloJetEta = jet.first->eta();
	    _hltL2CaloJetPhi = jet.first->phi();
	    _hltL2CaloJetIso = jet.second;
	  }

      }

    }



    //! TagAndProbe on L1T taus

    edm::Handle< BXVector<l1t::Tau> >  L1TauHandle;
    iEvent.getByToken(_L1TauTag, L1TauHandle);

    float minDR = 0.5; //Uncomment for new match algo

    for (l1t::TauBxCollection::const_iterator bx0TauIt = L1TauHandle->begin(0); bx0TauIt != L1TauHandle->end(0) ; bx0TauIt++)
    {
        const float dR = deltaR(*tau, *bx0TauIt);
	const l1t::Tau& l1tTau = *bx0TauIt;

	//cout<<"FW Tau, pT = "<<l1tTau.pt()<<", eta = "<<l1tTau.eta()<<", phi = "<<l1tTau.phi()<<endl;

        if (dR < minDR) //Uncomment for new match algo
        //if (dR < 0.5) //Uncomment for old match algo
        {
            minDR = dR; //Uncomment for new match algo
            _l1tPt = l1tTau.pt();
            _l1tEta = l1tTau.eta();
            _l1tPhi = l1tTau.phi();
            _l1tIso = l1tTau.hwIso();
            _l1tQual = l1tTau.hwQual();
        }
    }

    edm::Handle< BXVector<l1t::Tau> >  L1EmuTauHandle;
    try {iEvent.getByToken(_L1EmuTauTag, L1EmuTauHandle);} catch (...) {;}

    if (L1EmuTauHandle.isValid())
      {
	minDR = 0.5;
	
	for (l1t::TauBxCollection::const_iterator bx0EmuTauIt = L1EmuTauHandle->begin(0); bx0EmuTauIt != L1EmuTauHandle->end(0) ; bx0EmuTauIt++)
	  {
	    const float dR = deltaR(*tau, *bx0EmuTauIt);
	    const l1t::Tau& l1tEmuTau = *bx0EmuTauIt;
	    
	    //cout<<"Emul Tau, pT = "<<l1tEmuTau.pt()<<", eta = "<<l1tEmuTau.eta()<<", phi = "<<l1tEmuTau.phi()<<endl;
	    
	    if (dR < minDR) //Uncomment for new match algo
	      {
		minDR = dR; //Uncomment for new match algo
		_l1tEmuPt        = l1tEmuTau.pt();
		_l1tEmuEta       = l1tEmuTau.eta();
		_l1tEmuPhi       = l1tEmuTau.phi();
		_l1tEmuIso       = l1tEmuTau.hwIso();
		_l1tEmuNTT       = l1tEmuTau.nTT();
		_l1tEmuQual      = l1tEmuTau.hwQual();
		_l1tEmuHasEM     = l1tEmuTau.hasEM();
		_l1tEmuIsMerged  = l1tEmuTau.isMerged();
		_l1tEmuTowerIEta = l1tEmuTau.towerIEta();
		_l1tEmuTowerIPhi = l1tEmuTau.towerIPhi();
		_l1tEmuRawEt     = l1tEmuTau.rawEt();
		_l1tEmuIsoEt     = l1tEmuTau.isoEt();
		
	      }
	  }
      }

    _tauPt = tau -> pt();
    _tauEta = tau -> eta();
    _tauPhi = tau -> phi();
    _tauDM = tau -> decayMode();
    
    _byLooseCombinedIsolationDeltaBetaCorr3Hits = tau->tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits");
    _byMediumCombinedIsolationDeltaBetaCorr3Hits = tau->tauID("byMediumCombinedIsolationDeltaBetaCorr3Hits");
    _byTightCombinedIsolationDeltaBetaCorr3Hits = tau->tauID("byTightCombinedIsolationDeltaBetaCorr3Hits");
    _byVLooseIsolationMVArun2v1DBoldDMwLT = tau->tauID("byVLooseIsolationMVArun2v1DBoldDMwLT");
    _byLooseIsolationMVArun2v1DBoldDMwLT = tau->tauID("byLooseIsolationMVArun2v1DBoldDMwLT");
    _byMediumIsolationMVArun2v1DBoldDMwLT = tau->tauID("byMediumIsolationMVArun2v1DBoldDMwLT");
    _byTightIsolationMVArun2v1DBoldDMwLT = tau->tauID("byTightIsolationMVArun2v1DBoldDMwLT");
    _byVTightIsolationMVArun2v1DBoldDMwLT = tau->tauID("byVTightIsolationMVArun2v1DBoldDMwLT");
    _byVLooseIsolationMVArun2v1DBnewDMwLT = tau->tauID("byVLooseIsolationMVArun2v1DBnewDMwLT");
    _byLooseIsolationMVArun2v1DBnewDMwLT = tau->tauID("byLooseIsolationMVArun2v1DBnewDMwLT");
    _byMediumIsolationMVArun2v1DBnewDMwLT = tau->tauID("byMediumIsolationMVArun2v1DBnewDMwLT");
    _byTightIsolationMVArun2v1DBnewDMwLT = tau->tauID("byTightIsolationMVArun2v1DBnewDMwLT");
    _byVTightIsolationMVArun2v1DBnewDMwLT = tau->tauID("byVTightIsolationMVArun2v1DBnewDMwLT");
    _byLooseIsolationMVArun2v1DBdR03oldDMwLT = tau->tauID("byLooseIsolationMVArun2v1DBdR03oldDMwLT");
    _byMediumIsolationMVArun2v1DBdR03oldDMwLT = tau->tauID("byMediumIsolationMVArun2v1DBdR03oldDMwLT");
    _byTightIsolationMVArun2v1DBdR03oldDMwLT = tau->tauID("byTightIsolationMVArun2v1DBdR03oldDMwLT");
    _byVTightIsolationMVArun2v1DBdR03oldDMwLT = tau->tauID("byVTightIsolationMVArun2v1DBdR03oldDMwLT");
    
    _againstMuonLoose3 = tau->tauID("againstMuonLoose3");
    _againstMuonTight3 = tau->tauID("againstMuonTight3");
    _againstElectronVLooseMVA6 = tau->tauID("againstElectronVLooseMVA6");
    _againstElectronLooseMVA6 = tau->tauID("againstElectronLooseMVA6");
    _againstElectronMediumMVA6 = tau->tauID("againstElectronMediumMVA6");
    _againstElectronTightMVA6 = tau->tauID("againstElectronTightMVA6");
    _againstElectronVTightMVA6 = tau->tauID("againstElectronVTightMVA6");

    if(muonHandle.isValid()){
      _muonPt=muon->pt();
      _muonEta=muon->eta();
      _muonPhi=muon->phi();
      _mVis = (muon->p4() + tau->p4()).mass();
    }

    _Nvtx = vertexes->size();
    
    _nTruePU = -99;
    	
    if (_isMC) {

      std::vector<PileupSummaryInfo>::const_iterator PVI;
      for(PVI = puInfo->begin(); PVI != puInfo->end(); ++PVI) {
	if(PVI->getBunchCrossing() == 0) { 
	  float nTrueInt = PVI->getTrueNumInteractions();
	  cout<<"nTrueInt="<<PVI->getTrueNumInteractions()<<endl;
	  _nTruePU = nTrueInt;  
	  //break;
	}
      }

    }

  	
    _tauTriggerBits = _tauTriggerBitSet.to_ulong();

    //Gen-matching

    if(_isMC){

      const edm::View<pat::GenericParticle>* genparts = genPartHandle.product();
      _tau_genindex = this->GenIndex(tau,genparts);

    }



    //std::cout << "++++++++++ FILL ++++++++++" << std::endl;

    if(foundMuTrigger)
      _tree -> Fill();

}

bool Ntuplizer::hasFilters(const pat::TriggerObjectStandAlone&  obj , const std::vector<std::string>& filtersToLookFor) {

    const std::vector<std::string>& eventLabels = obj.filterLabels();
    for (const std::string& filter : filtersToLookFor)
    {
        //Looking for matching filters
        bool found = false;
        for (const std::string& label : eventLabels)
        {

            if (label == filter)
            {
                //std::cout << "#### FOUND FILTER " << label << " == " << filter << " ####" << std::endl;
                found = true;
            }
        }
        if(!found) return false;
    }

    return true;
}



int Ntuplizer::GenIndex(const pat::TauRef& tau, const edm::View<pat::GenericParticle>* genparts){
	
  float dRmin = 1.0;
  int genMatchInd = -1;

  for(edm::View<pat::GenericParticle>::const_iterator genpart = genparts->begin(); genpart!=genparts->end();++genpart){
	  
    int flags = genpart->userInt ("generalGenFlags");    
    int apdg = abs(genpart->pdgId());
    float pT = genpart->p4().pt();

    if( !( apdg==11 || apdg==13 || apdg==66615) ) continue;

    if( apdg==11 || apdg==13){
      if( !(pT>8 && (flags&1 || (flags>>5)&1)) ) continue;
    }
    else if(apdg==66615){
      int tauMothInd = genpart->userInt("TauMothIndex");
      pat::GenericParticle mother = (*genparts)[tauMothInd];
      int flags_tau = mother.userInt ("generalGenFlags");
      if( !(pT>15 && flags_tau&1) ) continue;
    }

    float dR = deltaR(*tau,*genpart);
    if(dR<0.2 && dR<dRmin){
      dRmin = dR;
      if(apdg==11){
	if(flags&1) genMatchInd = 1;
	else if((flags>>5)&1) genMatchInd = 3;
      }
      else if(apdg==13){
	if(flags&1) genMatchInd = 2;
	else if((flags>>5)&1) genMatchInd = 4;
      }
      else if(apdg==66615)
	genMatchInd = 5;
    }

  }

  return genMatchInd;


}




float Ntuplizer::ComputeMT (math::XYZTLorentzVector visP4, const pat::MET& met)
{
  math::XYZTLorentzVector METP4 (met.pt()*TMath::Cos(met.phi()), met.pt()*TMath::Sin(met.phi()), 0, met.pt());
  float scalSum = met.pt() + visP4.pt();

  math::XYZTLorentzVector vecSum (visP4);
  vecSum += METP4;
  float vecSumPt = vecSum.pt();
  return sqrt (scalSum*scalSum - vecSumPt*vecSumPt);
}




#include <FWCore/Framework/interface/MakerMacros.h>
DEFINE_FWK_MODULE(Ntuplizer);

#endif //NTUPLIZER_H
