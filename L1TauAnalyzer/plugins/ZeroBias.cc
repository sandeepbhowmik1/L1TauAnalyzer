#ifndef ZeroBias_H
#define ZeroBias_H

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


#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <FWCore/Framework/interface/Frameworkfwd.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/Utilities/interface/InputTag.h>
#include <DataFormats/PatCandidates/interface/Muon.h>
#include <DataFormats/PatCandidates/interface/Tau.h>
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/L1Trigger/interface/Tau.h"
#include "DataFormats/L1Trigger/interface/Jet.h"
#include "DataFormats/L1Trigger/interface/EtSum.h"
#include "DataFormats/L1Trigger/interface/EGamma.h"
#include "DataFormats/L1Trigger/interface/Muon.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/BTauReco/interface/JetTag.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/TauReco/interface/PFTauFwd.h"
#include "RecoTauTag/RecoTau/interface/RecoTauCommonUtilities.h"
#include <boost/foreach.hpp>
#include "DataFormats/TauReco/interface/PFJetChargedHadronAssociation.h"
#include "DataFormats/TauReco/interface/JetPiZeroAssociation.h"

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

class ZeroBias : public edm::EDAnalyzer {
public:
  /// Constructor
  explicit ZeroBias(const edm::ParameterSet&);
  /// Destructor
  virtual ~ZeroBias();

private:
  //----edm control---
  virtual void beginJob() ;
  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob();
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
  void Initialize();
  bool hasFilters(const pat::TriggerObjectStandAlone&  obj , const std::vector<std::string>& filtersToLookFor);
  Long64_t FindTriggerBit(const vector<string> foundPaths, const vector<int> indexOfPaths, const edm::Handle<edm::TriggerResults>& triggerResults);

  TTree *_tree;
  TTree *_triggerNamesTree;
  std::string _treeName;
  // -------------------------------------
  // variables to be filled in output tree
  ULong64_t       _indexevents;
  Int_t           _runNumber;
  Int_t           _lumi;
  unsigned long _EventTriggerBits;

  std::vector<int> _l1tQual;
  std::vector<float> _l1tPt;
  std::vector<float> _l1tEta;
  std::vector<float> _l1tPhi;
  std::vector<int> _l1tIso;

  std::vector<int> _l1tEmuQual;
  std::vector<float> _l1tEmuPt;
  std::vector<float> _l1tEmuEta;
  std::vector<float> _l1tEmuPhi;
  std::vector<int> _l1tEmuIso;
  std::vector<int> _l1tEmuNTT;
  std::vector<int> _l1tEmuHasEM;
  std::vector<int> _l1tEmuIsMerged;
  std::vector<int> _l1tEmuTowerIEta;
  std::vector<int> _l1tEmuTowerIPhi;
  std::vector<int> _l1tEmuRawEt;
  std::vector<int> _l1tEmuIsoEt;
        
  std::vector<int> _l1tQualJet;
  std::vector<float> _l1tPtJet;
  std::vector<float> _l1tEtaJet;
  std::vector<float> _l1tPhiJet;
  std::vector<int> _l1tIsoJet;
  std::vector<int> _l1tTowerIEtaJet;
  std::vector<int> _l1tTowerIPhiJet;
  std::vector<int> _l1tRawEtJet;  
        
  std::vector<int> _l1tEmuQualJet;
  std::vector<float> _l1tEmuPtJet;
  std::vector<float> _l1tEmuEtaJet;
  std::vector<float> _l1tEmuPhiJet;
  std::vector<int> _l1tEmuIsoJet;
  std::vector<int> _l1tEmuTowerIEtaJet;
  std::vector<int> _l1tEmuTowerIPhiJet;
  std::vector<int> _l1tEmuRawEtJet; 

  std::vector<short int> _l1tSumType;
  std::vector<float> _l1tSumEt;
  std::vector<float> _l1tSumPhi;
  std::vector<float> _l1tSumIEt;
  std::vector<float> _l1tSumIPhi;

  std::vector<short int> _l1tEmuSumType;
  std::vector<float> _l1tEmuSumEt;
  std::vector<float> _l1tEmuSumPhi;
  std::vector<float> _l1tEmuSumIEt;
  std::vector<float> _l1tEmuSumIPhi;

  std::vector<int> _l1tEGQual;
  std::vector<float> _l1tEGPt;
  std::vector<float> _l1tEGEta;
  std::vector<float> _l1tEGPhi;
  std::vector<int> _l1tEGIso;

  std::vector<int> _l1tEmuEGQual;
  std::vector<float> _l1tEmuEGPt;
  std::vector<float> _l1tEmuEGEta;
  std::vector<float> _l1tEmuEGPhi;
  std::vector<int> _l1tEmuEGIso;
  std::vector<int> _l1tEmuEGNTT;
  std::vector<int> _l1tEmuEGTowerIEta;
  std::vector<int> _l1tEmuEGTowerIPhi;
  std::vector<int> _l1tEmuEGRawEt;
  std::vector<int> _l1tEmuEGIsoEt;

  std::vector<int> _l1tMuQual;
  std::vector<float> _l1tMuPt;
  std::vector<float> _l1tMuEta;
  std::vector<float> _l1tMuPhi;

  std::vector<int> _l1tEmuMuQual;
  std::vector<float> _l1tEmuMuPt;
  std::vector<float> _l1tEmuMuEta;
  std::vector<float> _l1tEmuMuPhi;
  std::vector<int> _l1tEmuMuIso;

  std::vector<float> _hltTauPt;
  std::vector<float> _hltTauEta;
  std::vector<float> _hltTauPhi;
  std::vector<int> _hltTauTriggerBits;

  std::vector<float> _hltMuPt;
  std::vector<float> _hltMuEta;
  std::vector<float> _hltMuPhi;
  std::vector<int> _hltMuTriggerBits;

  std::vector<float> _hltElePt;
  std::vector<float> _hltEleEta;
  std::vector<float> _hltElePhi;
  std::vector<int> _hltEleTriggerBits;
  
  int _hltL2CaloJet_N;
  std::vector<float> _hltL2CaloJet_Pt;
  std::vector<float> _hltL2CaloJet_Eta;
  std::vector<float> _hltL2CaloJet_Phi;
  std::vector<float> _hltL2CaloJet_Iso;

  int _hltL2CaloJetIsoPix_N;
  std::vector<float> _hltL2CaloJetIsoPix_Pt;
  std::vector<float> _hltL2CaloJetIsoPix_Eta;
  std::vector<float> _hltL2CaloJetIsoPix_Phi;

  int _hltPixelTrack_N;
  std::vector<float> _hltPixelTrack_Pt;
  std::vector<float> _hltPixelTrack_Eta;
  std::vector<float> _hltPixelTrack_Phi;

  int _hltMergedTrackTauReg_N;
  std::vector<float> _hltMergedTrackTauReg_Pt;
  std::vector<float> _hltMergedTrackTauReg_Eta;
  std::vector<float> _hltMergedTrackTauReg_Phi;

  int _hltPFRegCand_N;
  std::vector<float> _hltPFRegCand_Pt;
  std::vector<float> _hltPFRegCand_Eta;
  std::vector<float> _hltPFRegCand_Phi;

  int _hltAK4PFRegJet_N;
  std::vector<float> _hltAK4PFRegJet_Pt;
  std::vector<float> _hltAK4PFRegJet_Eta;
  std::vector<float> _hltAK4PFRegJet_Phi;

  int _hltPFRegCandJetReg_N;
  std::vector<float> _hltPFRegCandJetReg_Pt;
  std::vector<float> _hltPFRegCandJetReg_Eta;
  std::vector<float> _hltPFRegCandJetReg_Phi;
  
  int _hltTauPFJetsRecoTauChargedHadronsReg_N;
  std::vector<float> _hltTauPFJetsRecoTauChargedHadronsReg_Pt;
  std::vector<float> _hltTauPFJetsRecoTauChargedHadronsReg_Eta;
  std::vector<float> _hltTauPFJetsRecoTauChargedHadronsReg_Phi;

  int _hltPFTauPiZerosReg_N;
  std::vector<float> _hltPFTauPiZerosReg_Pt;
  std::vector<float> _hltPFTauPiZerosReg_Eta;
  std::vector<float> _hltPFTauPiZerosReg_Phi;

  int _hltPFTauSansRefReg_N;
  std::vector<float> _hltPFTauSansRefReg_Pt;
  std::vector<float> _hltPFTauSansRefReg_Eta;
  std::vector<float> _hltPFTauSansRefReg_Phi;

  int _hltPFTauTrack_N;
  std::vector<float> _hltPFTauTrack_Pt;
  std::vector<float> _hltPFTauTrack_Eta;
  std::vector<float> _hltPFTauTrack_Phi;

  int _hltPFTauTrackReg_N;
  std::vector<float> _hltPFTauTrackReg_Pt;
  std::vector<float> _hltPFTauTrackReg_Eta;
  std::vector<float> _hltPFTauTrackReg_Phi;

  int _hltPFTau35TrackPt1Reg_N;
  std::vector<float> _hltPFTau35TrackPt1Reg_Pt;
  std::vector<float> _hltPFTau35TrackPt1Reg_Eta;
  std::vector<float> _hltPFTau35TrackPt1Reg_Phi;

  edm::EDGetTokenT<l1t::TauBxCollection> _L1TauTag  ;
  edm::EDGetTokenT<l1t::TauBxCollection> _L1EmuTauTag  ;
  edm::EDGetTokenT<l1t::JetBxCollection> _l1tJetTag;
  edm::EDGetTokenT<l1t::JetBxCollection> _l1tEmuJetTag;
  edm::EDGetTokenT<l1t::EtSumBxCollection> _l1tSumTag;
  edm::EDGetTokenT<l1t::EtSumBxCollection> _l1tEmuSumTag;
  edm::EDGetTokenT<l1t::EGammaBxCollection> _L1EGTag  ;
  edm::EDGetTokenT<l1t::EGammaBxCollection> _L1EmuEGTag  ;
  edm::EDGetTokenT<l1t::MuonBxCollection> _L1MuTag  ;
  edm::EDGetTokenT<l1t::MuonBxCollection> _L1EmuMuTag  ;
  edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> _triggerObjects;
  edm::EDGetTokenT<edm::TriggerResults> _triggerBits;

  edm::EDGetTokenT<reco::CaloJetCollection> _hltL2CaloJet_ForIsoPix_Tag;
  edm::EDGetTokenT<reco::JetTagCollection> _hltL2CaloJet_ForIsoPix_IsoTag;

  edm::EDGetTokenT<reco::TrackCollection> _hltPixelTracksRegForTau_Tag;
  edm::EDGetTokenT<reco::TrackCollection> _hltMergedTracksTauReg_Tag;
  edm::EDGetTokenT<reco::PFCandidateCollection> _hltPFRegCand_Tag;
  edm::EDGetTokenT<reco::PFJetCollection> _hltAK4PFRegJet_Tag;
  edm::EDGetTokenT<reco::PFTauCollection> _hltPFTauSansRefReg_Tag;

  edm::EDGetTokenT<reco::CandidateView> _jet_token;
  edm::EDGetTokenT<edm::Association<reco::PFJetCollection> > _hltPFJetRegion_Tag;
  edm::EDGetTokenT<reco::PFJetChargedHadronAssociation> _chargedHadron_token;
  edm::EDGetTokenT<reco::JetPiZeroAssociation> _piZero_token;

  //!Contains the parameters
  tVParameterSet _parameters;

  edm::InputTag _processName;
  //! Maximum
  std::bitset<NUMBER_OF_MAXIMUM_TRIGGERS> _EventTriggerBitSet;
  HLTConfigProvider _hltConfig;

  vector<string> _triggerlist;
  vector<int> _indexOfPath;
  vector<string> _foundPaths;

};

/*
  ██ ███    ███ ██████  ██      ███████ ███    ███ ███████ ███    ██ ████████  █████  ████████ ██  ██████  ███    ██
  ██ ████  ████ ██   ██ ██      ██      ████  ████ ██      ████   ██    ██    ██   ██    ██    ██ ██    ██ ████   ██
  ██ ██ ████ ██ ██████  ██      █████   ██ ████ ██ █████   ██ ██  ██    ██    ███████    ██    ██ ██    ██ ██ ██  ██
  ██ ██  ██  ██ ██      ██      ██      ██  ██  ██ ██      ██  ██ ██    ██    ██   ██    ██    ██ ██    ██ ██  ██ ██
  ██ ██      ██ ██      ███████ ███████ ██      ██ ███████ ██   ████    ██    ██   ██    ██    ██  ██████  ██   ████
*/

// ----Constructor and Destructor -----
ZeroBias::ZeroBias(const edm::ParameterSet& iConfig) :
  _L1TauTag       (consumes<l1t::TauBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1Tau"))),
  _L1EmuTauTag    (consumes<l1t::TauBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1EmuTau"))),
  _l1tJetTag      (consumes<l1t::JetBxCollection>                     (iConfig.getParameter<edm::InputTag>("l1tJetCollection"))),
  _l1tEmuJetTag   (consumes<l1t::JetBxCollection>                     (iConfig.getParameter<edm::InputTag>("l1tEmuJetCollection"))),
  _l1tSumTag      (consumes<l1t::EtSumBxCollection>                     (iConfig.getParameter<edm::InputTag>("L1SumCollection"))),
  _l1tEmuSumTag   (consumes<l1t::EtSumBxCollection>                     (iConfig.getParameter<edm::InputTag>("L1EmuSumCollection"))),
  _L1EGTag       (consumes<l1t::EGammaBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1EG"))),
  _L1EmuEGTag    (consumes<l1t::EGammaBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1EmuEG"))),
  _L1MuTag       (consumes<l1t::MuonBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1Mu"))),
  _L1EmuMuTag    (consumes<l1t::MuonBxCollection>                   (iConfig.getParameter<edm::InputTag>("L1EmuMu"))),
  _triggerObjects (consumes<pat::TriggerObjectStandAloneCollection> (iConfig.getParameter<edm::InputTag>("triggerSet"))),
  _triggerBits    (consumes<edm::TriggerResults>                    (iConfig.getParameter<edm::InputTag>("triggerResultsLabel"))),
  _hltL2CaloJet_ForIsoPix_Tag(consumes<reco::CaloJetCollection>     (iConfig.getParameter<edm::InputTag>("L2CaloJet_ForIsoPix_Collection"))),
  _hltL2CaloJet_ForIsoPix_IsoTag(consumes<reco::JetTagCollection>   (iConfig.getParameter<edm::InputTag>("L2CaloJet_ForIsoPix_IsoCollection"))),
  _hltPixelTracksRegForTau_Tag(consumes<reco::TrackCollection>(iConfig.getParameter<edm::InputTag>("PixelTrackCollection"))),
  _hltMergedTracksTauReg_Tag(consumes<reco::TrackCollection>(iConfig.getParameter<edm::InputTag>("MergedTrackCollection"))),
  _hltPFRegCand_Tag(consumes<reco::PFCandidateCollection>(iConfig.getParameter<edm::InputTag>("PFRegCandCollection"))),
  _hltAK4PFRegJet_Tag(consumes<reco::PFJetCollection>(iConfig.getParameter<edm::InputTag>("AK4PFRegJetCollection"))),
  _hltPFTauSansRefReg_Tag(consumes<reco::PFTauCollection>(iConfig.getParameter<edm::InputTag>("PFTauSansRefRegCollection"))),
  _jet_token(consumes<reco::CandidateView>(iConfig.getParameter<edm::InputTag>("AK4PFRegJetCollection"))),
  _hltPFJetRegion_Tag(consumes<edm::Association<reco::PFJetCollection> >(iConfig.getParameter<edm::InputTag>("PFJetRegionCollection"))),
  _chargedHadron_token(consumes<reco::PFJetChargedHadronAssociation>(iConfig.getParameter<edm::InputTag>("PFJetChargedHadronAssociation"))),
  _piZero_token(consumes<reco::JetPiZeroAssociation>(iConfig.getParameter<edm::InputTag>("JetPiZeroAssociation")))
{
  this -> _treeName = iConfig.getParameter<std::string>("treeName");
  this -> _processName = iConfig.getParameter<edm::InputTag>("triggerResultsLabel");
    
  TString triggerName;
  edm::Service<TFileService> fs;
  this -> _triggerNamesTree = fs -> make<TTree>("triggerNames", "triggerNames");
  this -> _triggerNamesTree -> Branch("triggerNames",&triggerName);
    
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
    
    _triggerlist.push_back(pSet.hltPath);
    this -> _parameters.push_back(pSet);
    this -> _triggerNamesTree -> Fill();
  }
  

  this -> Initialize();
  return;
}

ZeroBias::~ZeroBias()
{}

void ZeroBias::beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup)
{

  Bool_t changedConfig = false;
  
  if(!this -> _hltConfig.init(iRun, iSetup, this -> _processName.process(), changedConfig)){
    edm::LogError("HLTMatchingFilter") << "Initialization of HLTConfigProvider failed!!";
    return;
  }


    const edm::TriggerNames::Strings& triggerNames = this -> _hltConfig.triggerNames();
    std::cout << " ===== LOOKING FOR THE PATH INDEXES =====" << std::endl;
    for (tParameterSet& parameter : this -> _parameters){
        const std::string& hltPath = parameter.hltPath;
        bool found = false;
        for(unsigned int j=0; j < triggerNames.size(); j++)
        {
	  std::cout << triggerNames[j] << std::endl;
            if (triggerNames[j].find(hltPath) != std::string::npos) {
                found = true;
                parameter.hltPathIndex = j;

                std::cout << "### FOUND AT INDEX #" << j << " --> " << triggerNames[j] << std::endl;
            }
        }
        if (!found) parameter.hltPathIndex = -1;
    }


    if(changedConfig || _foundPaths.size()==0){
      //cout<<"The present menu is "<<hltConfig.tableName()<<endl;
      _indexOfPath.clear();
      _foundPaths.clear();
    //for(size_t i=0; i<triggerPaths.size(); i++){
    // bool foundThisPath = false;
      for(size_t j=0; j<_hltConfig.triggerNames().size(); j++){
	string pathName = _hltConfig.triggerNames()[j];
	//TString tempo= hltConfig_.triggerNames()[j];
	//printf("%s\n",tempo.Data());
	//if(pathName==triggerPaths[i]){
	//foundThisPath = true;
	_indexOfPath.push_back(j);
	_foundPaths.push_back(pathName);
	
	cout << j << " - TTT: " << pathName << endl;
	//	  edm::LogInfo("AnalyzeRates")<<"Added path "<<pathName<<" to foundPaths";
      } 
    }


}

void ZeroBias::Initialize() {
  this -> _indexevents = 0;
  this -> _runNumber = 0;
  this -> _lumi = 0;

  this -> _l1tPt .clear();
  this -> _l1tEta .clear();
  this -> _l1tPhi .clear();
  this -> _l1tQual .clear();
  this -> _l1tIso .clear();

  this -> _l1tEmuPt .clear();
  this -> _l1tEmuEta .clear();
  this -> _l1tEmuPhi .clear();
  this -> _l1tEmuQual .clear();
  this -> _l1tEmuIso .clear();
  this -> _l1tEmuNTT .clear();
  this -> _l1tEmuHasEM .clear();
  this -> _l1tEmuIsMerged .clear();
  this -> _l1tEmuTowerIEta .clear();
  this -> _l1tEmuTowerIPhi .clear();
  this -> _l1tEmuRawEt .clear();
  this -> _l1tEmuIsoEt .clear();

  this -> _l1tPtJet        .clear();
  this -> _l1tEtaJet       .clear();
  this -> _l1tPhiJet       .clear();
  this -> _l1tIsoJet       .clear();
  this -> _l1tQualJet      .clear();
  this -> _l1tTowerIEtaJet .clear();
  this -> _l1tTowerIPhiJet .clear();
  this -> _l1tRawEtJet     .clear();

  this -> _l1tEmuPtJet        .clear();
  this -> _l1tEmuEtaJet       .clear();
  this -> _l1tEmuPhiJet       .clear();
  this -> _l1tEmuIsoJet       .clear();
  this -> _l1tEmuQualJet      .clear();
  this -> _l1tEmuTowerIEtaJet .clear();
  this -> _l1tEmuTowerIPhiJet .clear();
  this -> _l1tEmuRawEtJet     .clear();

  this -> _l1tSumType.clear();
  this -> _l1tSumEt.clear();
  this -> _l1tSumPhi.clear();
  this -> _l1tSumIEt.clear();
  this -> _l1tSumIPhi.clear();

  this -> _l1tEmuSumType.clear();
  this -> _l1tEmuSumEt.clear();
  this -> _l1tEmuSumPhi.clear();
  this -> _l1tEmuSumIEt.clear();
  this -> _l1tEmuSumIPhi.clear();

  this -> _l1tEGPt .clear();
  this -> _l1tEGEta .clear();
  this -> _l1tEGPhi .clear();
  this -> _l1tEGQual .clear();
  this -> _l1tEGIso .clear();

  this -> _l1tEmuEGPt .clear();
  this -> _l1tEmuEGEta .clear();
  this -> _l1tEmuEGPhi .clear();
  this -> _l1tEmuEGQual .clear();
  this -> _l1tEmuEGIso .clear();
  this -> _l1tEmuEGNTT .clear();
  this -> _l1tEmuEGTowerIEta .clear();
  this -> _l1tEmuEGTowerIPhi .clear();
  this -> _l1tEmuEGRawEt .clear();
  this -> _l1tEmuEGIsoEt .clear();

  this -> _l1tMuPt .clear();
  this -> _l1tMuEta .clear();
  this -> _l1tMuPhi .clear();
  this -> _l1tMuQual .clear();

  this -> _l1tEmuMuPt .clear();
  this -> _l1tEmuMuEta .clear();
  this -> _l1tEmuMuPhi .clear();
  this -> _l1tEmuMuQual .clear();

  this -> _hltTauPt .clear();
  this -> _hltTauEta .clear();
  this -> _hltTauPhi .clear();
  this -> _hltTauTriggerBits .clear();

  this -> _hltMuPt .clear();
  this -> _hltMuEta .clear();
  this -> _hltMuPhi .clear();
  this -> _hltMuTriggerBits .clear();

  this -> _hltElePt .clear();
  this -> _hltEleEta .clear();
  this -> _hltElePhi .clear();
  this -> _hltEleTriggerBits .clear();

  this -> _hltL2CaloJet_N = 0;
  this -> _hltL2CaloJet_Pt.clear();
  this -> _hltL2CaloJet_Eta.clear();
  this -> _hltL2CaloJet_Phi.clear();
  this -> _hltL2CaloJet_Iso.clear();

  this -> _hltL2CaloJetIsoPix_N = 0;
  this -> _hltL2CaloJetIsoPix_Pt.clear();
  this -> _hltL2CaloJetIsoPix_Eta.clear();
  this -> _hltL2CaloJetIsoPix_Phi.clear();

  this -> _hltPixelTrack_N = 0;
  this -> _hltPixelTrack_Pt.clear();
  this -> _hltPixelTrack_Eta.clear();
  this -> _hltPixelTrack_Phi.clear();

  this -> _hltMergedTrackTauReg_N = 0;
  this -> _hltMergedTrackTauReg_Pt.clear();
  this -> _hltMergedTrackTauReg_Eta.clear();
  this -> _hltMergedTrackTauReg_Phi.clear();

  this -> _hltPFRegCand_N = 0;
  this -> _hltPFRegCand_Pt.clear();
  this -> _hltPFRegCand_Eta.clear();
  this -> _hltPFRegCand_Phi.clear();

  this -> _hltAK4PFRegJet_N = 0;
  this -> _hltAK4PFRegJet_Pt.clear();
  this -> _hltAK4PFRegJet_Eta.clear();
  this -> _hltAK4PFRegJet_Phi.clear();

  this -> _hltPFRegCandJetReg_N = 0;
  this -> _hltPFRegCandJetReg_Pt.clear();
  this -> _hltPFRegCandJetReg_Eta.clear();
  this -> _hltPFRegCandJetReg_Phi.clear();
  
  this -> _hltTauPFJetsRecoTauChargedHadronsReg_N = 0;
  this -> _hltTauPFJetsRecoTauChargedHadronsReg_Pt.clear();
  this -> _hltTauPFJetsRecoTauChargedHadronsReg_Eta.clear();
  this -> _hltTauPFJetsRecoTauChargedHadronsReg_Phi.clear();

  this -> _hltPFTauPiZerosReg_N = 0;
  this -> _hltPFTauPiZerosReg_Pt.clear();
  this -> _hltPFTauPiZerosReg_Eta.clear();
  this -> _hltPFTauPiZerosReg_Phi.clear();
  

  this -> _hltPFTauSansRefReg_N = 0;
  this -> _hltPFTauSansRefReg_Pt.clear();
  this -> _hltPFTauSansRefReg_Eta.clear();
  this -> _hltPFTauSansRefReg_Phi.clear();

  this -> _hltPFTauTrack_N = 0;
  this -> _hltPFTauTrack_Pt.clear();
  this -> _hltPFTauTrack_Eta.clear();
  this -> _hltPFTauTrack_Phi.clear();

  this -> _hltPFTauTrackReg_N = 0;
  this -> _hltPFTauTrackReg_Pt.clear();
  this -> _hltPFTauTrackReg_Eta.clear();
  this -> _hltPFTauTrackReg_Phi.clear();

  this -> _hltPFTau35TrackPt1Reg_N = 0;
  this -> _hltPFTau35TrackPt1Reg_Pt.clear();
  this -> _hltPFTau35TrackPt1Reg_Eta.clear();
  this -> _hltPFTau35TrackPt1Reg_Phi.clear();

}


void ZeroBias::beginJob()
{
  edm::Service<TFileService> fs;
  this -> _tree = fs -> make<TTree>(this -> _treeName.c_str(), this -> _treeName.c_str());

  //Branches
  this -> _tree -> Branch("EventNumber",  &_indexevents);
  this -> _tree -> Branch("RunNumber",  &_runNumber);
  this -> _tree -> Branch("lumi",  &_lumi);
  this -> _tree -> Branch("EventTriggerBits", &_EventTriggerBits, "EventTriggerBits/L");

  this -> _tree -> Branch("l1tPt",  &_l1tPt);
  this -> _tree -> Branch("l1tEta", &_l1tEta);
  this -> _tree -> Branch("l1tPhi", &_l1tPhi);
  this -> _tree -> Branch("l1tQual", &_l1tQual);
  this -> _tree -> Branch("l1tIso", &_l1tIso);

  this -> _tree -> Branch("l1tEmuPt",  &_l1tEmuPt);
  this -> _tree -> Branch("l1tEmuEta", &_l1tEmuEta);
  this -> _tree -> Branch("l1tEmuPhi", &_l1tEmuPhi);
  this -> _tree -> Branch("l1tEmuQual", &_l1tEmuQual);
  this -> _tree -> Branch("l1tEmuIso", &_l1tEmuIso);
  this -> _tree -> Branch("l1tEmuNTT", &_l1tEmuNTT);
  this -> _tree -> Branch("l1tEmuHasEM", &_l1tEmuHasEM);
  this -> _tree -> Branch("l1tEmuIsMerged", &_l1tEmuIsMerged);
  this -> _tree -> Branch("l1tEmuTowerIEta", &_l1tEmuTowerIEta);
  this -> _tree -> Branch("l1tEmuTowerIPhi", &_l1tEmuTowerIPhi);
  this -> _tree -> Branch("l1tEmuRawEt", &_l1tEmuRawEt);
  this -> _tree -> Branch("l1tEmuIsoEt", &_l1tEmuIsoEt);

  this -> _tree -> Branch("l1tPtJet",  &_l1tPtJet);
  this -> _tree -> Branch("l1tEtaJet", &_l1tEtaJet);
  this -> _tree -> Branch("l1tPhiJet", &_l1tPhiJet);
  this -> _tree -> Branch("l1tQualJet", &_l1tQualJet);
  this -> _tree -> Branch("l1tIsoJet", &_l1tIsoJet);
  this -> _tree -> Branch("l1tTowerIEtaJet", &_l1tTowerIEtaJet);
  this -> _tree -> Branch("l1tTowerIPhiJet", &_l1tTowerIPhiJet);
  this -> _tree -> Branch("l1tRawEtJet", &_l1tRawEtJet);

  this -> _tree -> Branch("l1tEmuPtJet",  &_l1tEmuPtJet);
  this -> _tree -> Branch("l1tEmuEtaJet", &_l1tEmuEtaJet);
  this -> _tree -> Branch("l1tEmuPhiJet", &_l1tEmuPhiJet);
  this -> _tree -> Branch("l1tEmuQualJet", &_l1tEmuQualJet);
  this -> _tree -> Branch("l1tEmuIsoJet", &_l1tEmuIsoJet);
  this -> _tree -> Branch("l1tEmuTowerIEtaJet", &_l1tEmuTowerIEtaJet);
  this -> _tree -> Branch("l1tEmuTowerIPhiJet", &_l1tEmuTowerIPhiJet);
  this -> _tree -> Branch("l1tEmuRawEtJet", &_l1tEmuRawEtJet);

  this -> _tree -> Branch("l1tSumType", &_l1tSumType);
  this -> _tree -> Branch("l1tSumEt", &_l1tSumEt);
  this -> _tree -> Branch("l1tSumPhi", &_l1tSumPhi);
  this -> _tree -> Branch("l1tSumIEt", &_l1tSumIEt);
  this -> _tree -> Branch("l1tSumIPhi", &_l1tSumIPhi);

  this -> _tree -> Branch("l1tEmuSumType", &_l1tEmuSumType);
  this -> _tree -> Branch("l1tEmuSumEt", &_l1tEmuSumEt);
  this -> _tree -> Branch("l1tEmuSumPhi", &_l1tEmuSumPhi);
  this -> _tree -> Branch("l1tEmuSumIEt", &_l1tEmuSumIEt);
  this -> _tree -> Branch("l1tEmuSumIPhi", &_l1tEmuSumIPhi);

  this -> _tree -> Branch("l1tEGPt",  &_l1tEGPt);
  this -> _tree -> Branch("l1tEGEta", &_l1tEGEta);
  this -> _tree -> Branch("l1tEGPhi", &_l1tEGPhi);
  this -> _tree -> Branch("l1tEGQual", &_l1tEGQual);
  this -> _tree -> Branch("l1tEGIso", &_l1tEGIso);

  this -> _tree -> Branch("l1tEmuEGPt",  &_l1tEmuEGPt);
  this -> _tree -> Branch("l1tEmuEGEta", &_l1tEmuEGEta);
  this -> _tree -> Branch("l1tEmuEGPhi", &_l1tEmuEGPhi);
  this -> _tree -> Branch("l1tEmuEGQual", &_l1tEmuEGQual);
  this -> _tree -> Branch("l1tEmuEGIso", &_l1tEmuEGIso);
  this -> _tree -> Branch("l1tEmuEGNTT", &_l1tEmuEGNTT);
  this -> _tree -> Branch("l1tEmuEGTowerIEta", &_l1tEmuEGTowerIEta);
  this -> _tree -> Branch("l1tEmuEGTowerIPhi", &_l1tEmuEGTowerIPhi);
  this -> _tree -> Branch("l1tEmuEGRawEt", &_l1tEmuEGRawEt);
  this -> _tree -> Branch("l1tEmuEGIsoEt", &_l1tEmuEGIsoEt);

  this -> _tree -> Branch("l1tMuPt",  &_l1tMuPt);
  this -> _tree -> Branch("l1tMuEta", &_l1tMuEta);
  this -> _tree -> Branch("l1tMuPhi", &_l1tMuPhi);
  this -> _tree -> Branch("l1tMuQual", &_l1tMuQual);

  this -> _tree -> Branch("l1tEmuMuPt",  &_l1tEmuMuPt);
  this -> _tree -> Branch("l1tEmuMuEta", &_l1tEmuMuEta);
  this -> _tree -> Branch("l1tEmuMuPhi", &_l1tEmuMuPhi);
  this -> _tree -> Branch("l1tEmuMuQual", &_l1tEmuMuQual);

  this -> _tree -> Branch("hltTauPt",  &_hltTauPt);
  this -> _tree -> Branch("hltTauEta", &_hltTauEta);
  this -> _tree -> Branch("hltTauPhi", &_hltTauPhi);
  this -> _tree -> Branch("hltTauTriggerBits", &_hltTauTriggerBits);

  this -> _tree -> Branch("hltMuPt",  &_hltMuPt);
  this -> _tree -> Branch("hltMuEta", &_hltMuEta);
  this -> _tree -> Branch("hltMuPhi", &_hltMuPhi);
  this -> _tree -> Branch("hltMuTriggerBits", &_hltMuTriggerBits);

  this -> _tree -> Branch("hltElePt",  &_hltElePt);
  this -> _tree -> Branch("hltEleEta", &_hltEleEta);
  this -> _tree -> Branch("hltElePhi", &_hltElePhi);
  this -> _tree -> Branch("hltEleTriggerBits", &_hltEleTriggerBits);

  this -> _tree -> Branch("hltL2CaloJet_N",    &_hltL2CaloJet_N,    "hltL2CaloJet_N/I");
  this -> _tree -> Branch("hltL2CaloJet_Pt",   &_hltL2CaloJet_Pt);
  this -> _tree -> Branch("hltL2CaloJet_Eta",  &_hltL2CaloJet_Eta);
  this -> _tree -> Branch("hltL2CaloJet_Phi",  &_hltL2CaloJet_Phi);
  this -> _tree -> Branch("hltL2CaloJet_Iso",  &_hltL2CaloJet_Iso);

  this -> _tree -> Branch("hltL2CaloJetIsoPix_N",    &_hltL2CaloJetIsoPix_N,    "hltL2CaloJetIsoPix_N/I");
  this -> _tree -> Branch("hltL2CaloJetIsoPix_Pt",   &_hltL2CaloJetIsoPix_Pt);
  this -> _tree -> Branch("hltL2CaloJetIsoPix_Eta",  &_hltL2CaloJetIsoPix_Eta);
  this -> _tree -> Branch("hltL2CaloJetIsoPix_Phi",  &_hltL2CaloJetIsoPix_Phi);

  this -> _tree -> Branch("hltPixelTrack_N",    &_hltPixelTrack_N,    "hltPixelTrack_N/I");
  this -> _tree -> Branch("hltPixelTrack_Pt",   &_hltPixelTrack_Pt);
  this -> _tree -> Branch("hltPixelTrack_Eta",  &_hltPixelTrack_Eta);
  this -> _tree -> Branch("hltPixelTrack_Phi",  &_hltPixelTrack_Phi);

  this -> _tree -> Branch("hltMergedTrackTauReg_N",    &_hltMergedTrackTauReg_N,    "hltMergedTrackTauReg_N/I");
  this -> _tree -> Branch("hltMergedTrackTauReg_Pt",   &_hltMergedTrackTauReg_Pt);
  this -> _tree -> Branch("hltMergedTrackTauReg_Eta",  &_hltMergedTrackTauReg_Eta);
  this -> _tree -> Branch("hltMergedTrackTauReg_Phi",  &_hltMergedTrackTauReg_Phi);

  this -> _tree -> Branch("hltPFRegCand_N",    &_hltPFRegCand_N,    "hltPFRegCand_N/I");
  this -> _tree -> Branch("hltPFRegCand_Pt",   &_hltPFRegCand_Pt);
  this -> _tree -> Branch("hltPFRegCand_Eta",  &_hltPFRegCand_Eta);
  this -> _tree -> Branch("hltPFRegCand_Phi",  &_hltPFRegCand_Phi);

  this -> _tree -> Branch("hltAK4PFRegJet_N",    &_hltAK4PFRegJet_N,    "hltAK4PFRegJet_N/I");
  this -> _tree -> Branch("hltAK4PFRegJet_Pt",   &_hltAK4PFRegJet_Pt);
  this -> _tree -> Branch("hltAK4PFRegJet_Eta",  &_hltAK4PFRegJet_Eta);
  this -> _tree -> Branch("hltAK4PFRegJet_Phi",  &_hltAK4PFRegJet_Phi);

  this -> _tree -> Branch("hltPFRegCandJetReg_N",    &_hltPFRegCandJetReg_N,    "hltPFRegCandJetReg_N/I");
  this -> _tree -> Branch("hltPFRegCandJetReg_Pt",   &_hltPFRegCandJetReg_Pt);
  this -> _tree -> Branch("hltPFRegCandJetReg_Eta",  &_hltPFRegCandJetReg_Eta);
  this -> _tree -> Branch("hltPFRegCandJetReg_Phi",  &_hltPFRegCandJetReg_Phi);

  this -> _tree -> Branch("hltTauPFJetsRecoTauChargedHadronsReg_N",    &_hltTauPFJetsRecoTauChargedHadronsReg_N,    "hltTauPFJetsRecoTauChargedHadronsReg_N/I");
  this -> _tree -> Branch("hltTauPFJetsRecoTauChargedHadronsReg_Pt",   &_hltTauPFJetsRecoTauChargedHadronsReg_Pt);
  this -> _tree -> Branch("hltTauPFJetsRecoTauChargedHadronsReg_Eta",  &_hltTauPFJetsRecoTauChargedHadronsReg_Eta);
  this -> _tree -> Branch("hltTauPFJetsRecoTauChargedHadronsReg_Phi",  &_hltTauPFJetsRecoTauChargedHadronsReg_Phi);

  this -> _tree -> Branch("hltPFPFTauPiZerosReg_N",    &_hltPFTauPiZerosReg_N,    "hltPFTauPiZerosReg_N/I");
  this -> _tree -> Branch("hltPFPFTauPiZerosReg_Pt",   &_hltPFTauPiZerosReg_Pt);
  this -> _tree -> Branch("hltPFPFTauPiZerosReg_Eta",  &_hltPFTauPiZerosReg_Eta);
  this -> _tree -> Branch("hltPFPFTauPiZerosReg_Phi",  &_hltPFTauPiZerosReg_Phi);

  this -> _tree -> Branch("hltPFTauSansRefReg_N",    &_hltPFTauSansRefReg_N,    "hltPFTauSansRefReg_N/I");
  this -> _tree -> Branch("hltPFTauSansRefReg_Pt",   &_hltPFTauSansRefReg_Pt);
  this -> _tree -> Branch("hltPFTauSansRefReg_Eta",  &_hltPFTauSansRefReg_Eta);
  this -> _tree -> Branch("hltPFTauSansRefReg_Phi",  &_hltPFTauSansRefReg_Phi);

  this -> _tree -> Branch("hltPFTauTrack_N",    &_hltPFTauTrack_N,    "hltPFTauTrack_N/I");
  this -> _tree -> Branch("hltPFTauTrack_Pt",   &_hltPFTauTrack_Pt);
  this -> _tree -> Branch("hltPFTauTrack_Eta",  &_hltPFTauTrack_Eta);
  this -> _tree -> Branch("hltPFTauTrack_Phi",  &_hltPFTauTrack_Phi);

  this -> _tree -> Branch("hltPFTauTrackReg_N",    &_hltPFTauTrackReg_N,    "hltPFTauTrackReg_N/I");
  this -> _tree -> Branch("hltPFTauTrackReg_Pt",   &_hltPFTauTrackReg_Pt);
  this -> _tree -> Branch("hltPFTauTrackReg_Eta",  &_hltPFTauTrackReg_Eta);
  this -> _tree -> Branch("hltPFTauTrackReg_Phi",  &_hltPFTauTrackReg_Phi);

  this -> _tree -> Branch("hltPFTau35TrackPt1Reg_N",    &_hltPFTau35TrackPt1Reg_N,    "hltPFTau35TrackPt1Reg_N/I");
  this -> _tree -> Branch("hltPFTau35TrackPt1Reg_Pt",   &_hltPFTau35TrackPt1Reg_Pt);
  this -> _tree -> Branch("hltPFTau35TrackPt1Reg_Eta",  &_hltPFTau35TrackPt1Reg_Eta);
  this -> _tree -> Branch("hltPFTau35TrackPt1Reg_Phi",  &_hltPFTau35TrackPt1Reg_Phi);

  return;
}


void ZeroBias::endJob()
{
  return;
}


void ZeroBias::endRun(edm::Run const& iRun, edm::EventSetup const& iSetup)
{
  return;
}


void ZeroBias::analyze(const edm::Event& iEvent, const edm::EventSetup& eSetup)
{
  this -> Initialize();

  _indexevents = iEvent.id().event();
  _runNumber = iEvent.id().run();
  _lumi = iEvent.luminosityBlock();

  edm::Handle< BXVector<l1t::Tau> >  L1TauHandle;
  try {iEvent.getByToken(_L1TauTag, L1TauHandle);}  catch (...) {;}

  if(L1TauHandle.isValid()){
    for (l1t::TauBxCollection::const_iterator bx0TauIt = L1TauHandle->begin(0); bx0TauIt != L1TauHandle->end(0) ; bx0TauIt++)
      {
	const l1t::Tau& l1tTau = *bx0TauIt;
	
	//cout<<"FW Tau, pT = "<<l1tTau.pt()<<", eta = "<<l1tTau.eta()<<", phi = "<<l1tTau.phi()<<endl;
	
	this -> _l1tPt.push_back(l1tTau.pt());
	this -> _l1tEta.push_back(l1tTau.eta());
	this -> _l1tPhi.push_back(l1tTau.phi());
	this -> _l1tIso.push_back(l1tTau.hwIso());
	this -> _l1tQual.push_back(l1tTau.hwQual());
	
      }
  }

  edm::Handle< BXVector<l1t::Tau> >  L1EmuTauHandle;
  try {iEvent.getByToken(_L1EmuTauTag, L1EmuTauHandle);} catch (...) {;}

  if (L1EmuTauHandle.isValid())
    {	
      for (l1t::TauBxCollection::const_iterator bx0EmuTauIt = L1EmuTauHandle->begin(0); bx0EmuTauIt != L1EmuTauHandle->end(0) ; bx0EmuTauIt++)
	{
	  const l1t::Tau& l1tEmuTau = *bx0EmuTauIt;
	    
	  //cout<<"Emul Tau, pT = "<<l1tEmuTau.pt()<<", eta = "<<l1tEmuTau.eta()<<", phi = "<<l1tEmuTau.phi()<<endl;
	    
	  this -> _l1tEmuPt       .push_back(l1tEmuTau.pt());
	  this -> _l1tEmuEta      .push_back(l1tEmuTau.eta());
	  this -> _l1tEmuPhi      .push_back(l1tEmuTau.phi());
	  this -> _l1tEmuIso      .push_back(l1tEmuTau.hwIso());
	  this -> _l1tEmuNTT      .push_back(l1tEmuTau.nTT());
	  this -> _l1tEmuQual     .push_back(l1tEmuTau.hwQual());
	  this -> _l1tEmuHasEM    .push_back(l1tEmuTau.hasEM());
	  this -> _l1tEmuIsMerged .push_back(l1tEmuTau.isMerged());
	  this -> _l1tEmuTowerIEta.push_back(l1tEmuTau.towerIEta());
	  this -> _l1tEmuTowerIPhi.push_back(l1tEmuTau.towerIPhi());
	  this -> _l1tEmuRawEt    .push_back(l1tEmuTau.rawEt());
	  this -> _l1tEmuIsoEt    .push_back(l1tEmuTau.isoEt());

	}
    }

  edm::Handle<BXVector<l1t::Jet>> l1tJetHandle;
  try {iEvent.getByToken(this -> _l1tJetTag, l1tJetHandle);}  catch (...) {;}

  if(l1tJetHandle.isValid()){
    for(BXVector<l1t::Jet>::const_iterator jet = l1tJetHandle -> begin(0); jet != l1tJetHandle -> end(0) ; jet++)
      {
	
	this -> _l1tPtJet        . push_back(jet -> pt());
	this -> _l1tEtaJet       . push_back(jet -> eta());
	this -> _l1tPhiJet       . push_back(jet -> phi());
	this -> _l1tIsoJet       . push_back(jet -> hwIso());
	this -> _l1tQualJet      . push_back(jet -> hwQual());
	this -> _l1tTowerIEtaJet . push_back(jet -> towerIEta());
	this -> _l1tTowerIPhiJet . push_back(jet -> towerIPhi());
	this -> _l1tRawEtJet     . push_back(jet -> rawEt());
      }
  }

  edm::Handle<BXVector<l1t::Jet> > l1tEmuJetHandle;  
  try {iEvent.getByToken(this -> _l1tEmuJetTag, l1tEmuJetHandle);}  catch (...) {;}

  if (l1tEmuJetHandle.isValid()){

    for(BXVector<l1t::Jet>::const_iterator jet = l1tEmuJetHandle -> begin(0); jet != l1tEmuJetHandle -> end(0) ; jet++)
      {
	
	this -> _l1tEmuPtJet        . push_back(jet -> pt());
	this -> _l1tEmuEtaJet       . push_back(jet -> eta());
	this -> _l1tEmuPhiJet       . push_back(jet -> phi());
	this -> _l1tEmuIsoJet       . push_back(jet -> hwIso());
	this -> _l1tEmuQualJet      . push_back(jet -> hwQual());
	this -> _l1tEmuTowerIEtaJet . push_back(jet -> towerIEta());
	this -> _l1tEmuTowerIPhiJet . push_back(jet -> towerIPhi());
	this -> _l1tEmuRawEtJet     . push_back(jet -> rawEt());
      }
    
  }
  
  edm::Handle<BXVector<l1t::EtSum>> l1tSumHandle;
  try {iEvent.getByToken(this -> _l1tSumTag, l1tSumHandle);}  catch (...) {;}

  if(l1tSumHandle.isValid()){
    for(BXVector<l1t::EtSum>::const_iterator sum = l1tSumHandle -> begin(0); sum != l1tSumHandle -> end(0) ; sum++)
      {
	
	this -> _l1tSumType.push_back(sum -> getType());
	this -> _l1tSumEt  .  push_back(sum -> et());
	this -> _l1tSumPhi . push_back(sum -> phi());
	this -> _l1tSumIEt . push_back(sum -> hwPt());
	this -> _l1tSumIPhi. push_back(sum -> hwPhi());
      }
  }

  edm::Handle<BXVector<l1t::EtSum>> l1tEmuSumHandle;
  try {iEvent.getByToken(this -> _l1tEmuSumTag, l1tEmuSumHandle);}  catch (...) {;}

  if(l1tEmuSumHandle.isValid()){
    for(BXVector<l1t::EtSum>::const_iterator sum = l1tEmuSumHandle -> begin(0); sum != l1tEmuSumHandle -> end(0) ; sum++)
      {
	
	this -> _l1tEmuSumType.push_back(sum -> getType());
	this -> _l1tEmuSumEt  .  push_back(sum -> et());
	this -> _l1tEmuSumPhi . push_back(sum -> phi());
	this -> _l1tEmuSumIEt . push_back(sum -> hwPt());
	this -> _l1tEmuSumIPhi. push_back(sum -> hwPhi());
      }
  }

  edm::Handle< BXVector<l1t::EGamma> >  L1EGHandle;
  try {iEvent.getByToken(_L1EGTag, L1EGHandle);}  catch (...) {;}

  if(L1EGHandle.isValid()){
    for (l1t::EGammaBxCollection::const_iterator bx0EGIt = L1EGHandle->begin(0); bx0EGIt != L1EGHandle->end(0) ; bx0EGIt++)
      {
	const l1t::EGamma& l1tEG = *bx0EGIt;
	
	//cout<<"FW EG, pT = "<<l1tEG.pt()<<", eta = "<<l1tEG.eta()<<", phi = "<<l1tEG.phi()<<endl;
	
	this -> _l1tEGPt.push_back(l1tEG.pt());
	this -> _l1tEGEta.push_back(l1tEG.eta());
	this -> _l1tEGPhi.push_back(l1tEG.phi());
	this -> _l1tEGIso.push_back(l1tEG.hwIso());
	this -> _l1tEGQual.push_back(l1tEG.hwQual());
	
      }
  }

  edm::Handle< BXVector<l1t::EGamma> >  L1EmuEGHandle;
  try {iEvent.getByToken(_L1EmuEGTag, L1EmuEGHandle);} catch (...) {;}

  if (L1EmuEGHandle.isValid())
    {	
      for (l1t::EGammaBxCollection::const_iterator bx0EmuEGIt = L1EmuEGHandle->begin(0); bx0EmuEGIt != L1EmuEGHandle->end(0) ; bx0EmuEGIt++)
	{
	  const l1t::EGamma& l1tEmuEG = *bx0EmuEGIt;
	    
	  //cout<<"Emul EG, pT = "<<l1tEmuEG.pt()<<", eta = "<<l1tEmuEG.eta()<<", phi = "<<l1tEmuEG.phi()<<endl;
	    
	  this -> _l1tEmuEGPt       .push_back(l1tEmuEG.pt());
	  this -> _l1tEmuEGEta      .push_back(l1tEmuEG.eta());
	  this -> _l1tEmuEGPhi      .push_back(l1tEmuEG.phi());
	  this -> _l1tEmuEGIso      .push_back(l1tEmuEG.hwIso());
	  this -> _l1tEmuEGNTT      .push_back(l1tEmuEG.nTT());
	  this -> _l1tEmuEGQual     .push_back(l1tEmuEG.hwQual());
	  this -> _l1tEmuEGTowerIEta.push_back(l1tEmuEG.towerIEta());
	  this -> _l1tEmuEGTowerIPhi.push_back(l1tEmuEG.towerIPhi());
	  this -> _l1tEmuEGRawEt    .push_back(l1tEmuEG.rawEt());
	  this -> _l1tEmuEGIsoEt    .push_back(l1tEmuEG.isoEt());

	}
    }



  edm::Handle< BXVector<l1t::Muon> >  L1MuHandle;
  try {iEvent.getByToken(_L1MuTag, L1MuHandle);}  catch (...) {;}

  if(L1MuHandle.isValid()){
    for (l1t::MuonBxCollection::const_iterator bx0MuIt = L1MuHandle->begin(0); bx0MuIt != L1MuHandle->end(0) ; bx0MuIt++)
      {
	const l1t::Muon& l1tMu = *bx0MuIt;
	
	//cout<<"FW Mu, pT = "<<l1tMu.pt()<<", eta = "<<l1tMu.eta()<<", phi = "<<l1tMu.phi()<<endl;
	
	this -> _l1tMuPt.push_back(l1tMu.pt());
	this -> _l1tMuEta.push_back(l1tMu.eta());
	this -> _l1tMuPhi.push_back(l1tMu.phi());
	this -> _l1tMuQual.push_back(l1tMu.hwQual());
	
      }
  }

  edm::Handle< BXVector<l1t::Muon> >  L1EmuMuHandle;
  try {iEvent.getByToken(_L1EmuMuTag, L1EmuMuHandle);} catch (...) {;}

  if (L1EmuMuHandle.isValid())
    {	
      for (l1t::MuonBxCollection::const_iterator bx0EmuMuIt = L1EmuMuHandle->begin(0); bx0EmuMuIt != L1EmuMuHandle->end(0) ; bx0EmuMuIt++)
	{
	  const l1t::Muon& l1tEmuMu = *bx0EmuMuIt;
	    
	  //cout<<"Emul Mu, pT = "<<l1tEmuMu.pt()<<", eta = "<<l1tEmuMu.eta()<<", phi = "<<l1tEmuMu.phi()<<endl;
	    
	  this -> _l1tEmuMuPt       .push_back(l1tEmuMu.pt());
	  this -> _l1tEmuMuEta      .push_back(l1tEmuMu.eta());
	  this -> _l1tEmuMuPhi      .push_back(l1tEmuMu.phi());
	  this -> _l1tEmuMuQual     .push_back(l1tEmuMu.hwQual());

	}
    }






  edm::Handle<edm::TriggerResults> triggerBits;
  iEvent.getByToken(this -> _triggerBits, triggerBits);
  const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);
  this ->_EventTriggerBits = this->FindTriggerBit(_foundPaths,_indexOfPath,triggerBits);

  edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;
  try {iEvent.getByToken(this -> _triggerObjects, triggerObjects);}  catch (...) {;}

  if (triggerObjects.isValid()){
  
    for (pat::TriggerObjectStandAlone  obj : *triggerObjects)
      {
	
	obj.unpackPathNames(names);
	const edm::TriggerNames::Strings& triggerNames = names.triggerNames();
	
	bool hasTriggerTauType = obj.hasTriggerObjectType(trigger::TriggerTau);
	bool hasTriggerMuType = obj.hasTriggerObjectType(trigger::TriggerMuon);
	bool hasTriggerEleType = obj.hasTriggerObjectType(trigger::TriggerElectron);

	//Looking for the path
	unsigned int x = 0;
	for (const tParameterSet& parameter : this -> _parameters)
	  {
	    
	    
	    if ((parameter.hltPathIndex >= 0)&&(obj.hasPathName(triggerNames[parameter.hltPathIndex], true, false)))
	      {
		
		//cout<<"FOUND EVENT with HLT PATH "<<triggerNames[parameter.hltPathIndex]<<endl;
		
		this -> _EventTriggerBitSet[x] = true;
		
		if(hasTriggerTauType)
		  {
		    //std::cout << "#### FOUND TAU WITH HLT PATH " << x << " ####" << std::endl;
		    this -> _hltTauPt.push_back(obj.pt());
		    this -> _hltTauEta.push_back(obj.eta());
		    this -> _hltTauPhi.push_back(obj.phi());
		    this -> _hltTauTriggerBits.push_back( x );
		  }
		
		if(hasTriggerMuType)
		  {
		    //std::cout << "#### FOUND MUON WITH HLT PATH " << x << " ####" << std::endl;
		    this -> _hltMuPt.push_back(obj.pt());
		    this -> _hltMuEta.push_back(obj.eta());
		    this -> _hltMuPhi.push_back(obj.phi());
		    this -> _hltMuTriggerBits.push_back( x );
		  }
		
		if(hasTriggerEleType)
		  {
		    //std::cout << "#### FOUND ELE WITH HLT PATH " << x << " ####" << std::endl;
		    this -> _hltElePt.push_back(obj.pt());
		    this -> _hltEleEta.push_back(obj.eta());
		    this -> _hltElePhi.push_back(obj.phi());
		    this -> _hltEleTriggerBits.push_back( x );
		  }
		
	      }
	    
	    x++;
	  }
	
	const std::vector<std::string>& L2CaloJetIsoPix_filters = {"hltL2TauIsoFilter"};
	if (this -> hasFilters(obj, L2CaloJetIsoPix_filters)){
	  this -> _hltL2CaloJetIsoPix_N++;	  
	  this -> _hltL2CaloJetIsoPix_Pt.push_back(obj.pt());
	  this -> _hltL2CaloJetIsoPix_Eta.push_back(obj.eta());
	  this -> _hltL2CaloJetIsoPix_Phi.push_back(obj.phi());	  
	}

	const std::vector<std::string>& PFTauTrack_filters = {"hltPFTauTrack"};
	if (this -> hasFilters(obj, PFTauTrack_filters)){
	  this -> _hltPFTauTrack_N++;	  
	  this -> _hltPFTauTrack_Pt.push_back(obj.pt());
	  this -> _hltPFTauTrack_Eta.push_back(obj.eta());
	  this -> _hltPFTauTrack_Phi.push_back(obj.phi());
	}

	const std::vector<std::string>& PFTauTrackReg_filters = {"hltPFTauTrackReg"};
	if (this -> hasFilters(obj, PFTauTrackReg_filters)){
	  this -> _hltPFTauTrackReg_N++;	  
	  this -> _hltPFTauTrackReg_Pt.push_back(obj.pt());
	  this -> _hltPFTauTrackReg_Eta.push_back(obj.eta());
	  this -> _hltPFTauTrackReg_Phi.push_back(obj.phi());
	}

	const std::vector<std::string>& PFTau35TrackPt1Reg_filters = {"hltDoublePFTau35TrackPt1Reg"};
	if (this -> hasFilters(obj, PFTau35TrackPt1Reg_filters)){
	  this -> _hltPFTau35TrackPt1Reg_N++;	  
	  this -> _hltPFTau35TrackPt1Reg_Pt.push_back(obj.pt());
	  this -> _hltPFTau35TrackPt1Reg_Eta.push_back(obj.eta());
	  this -> _hltPFTau35TrackPt1Reg_Phi.push_back(obj.phi());
	}

      }

  }



  edm::Handle< reco::CaloJetCollection > L2CaloJets_ForIsoPix_Handle;
  try {iEvent.getByToken(_hltL2CaloJet_ForIsoPix_Tag, L2CaloJets_ForIsoPix_Handle);}  catch (...) {;}

  edm::Handle< reco::JetTagCollection > L2CaloJets_ForIsoPix_IsoHandle;
  try {iEvent.getByToken(_hltL2CaloJet_ForIsoPix_IsoTag, L2CaloJets_ForIsoPix_IsoHandle);}  catch (...) {;}
  

  if(L2CaloJets_ForIsoPix_Handle.isValid() && L2CaloJets_ForIsoPix_IsoHandle.isValid()){

    for (auto const &  jet : *L2CaloJets_ForIsoPix_IsoHandle){
      edm::Ref<reco::CaloJetCollection> jetRef = edm::Ref<reco::CaloJetCollection>(L2CaloJets_ForIsoPix_Handle,jet.first.key());
      _hltL2CaloJet_N++;
      _hltL2CaloJet_Pt.push_back(jet.first->pt());
      _hltL2CaloJet_Eta.push_back(jet.first->eta());
      _hltL2CaloJet_Phi.push_back(jet.first->phi());
      _hltL2CaloJet_Iso.push_back(jet.second);
   
    }

  }


  edm::Handle< reco::TrackCollection > PixelTracks_Handle;
  try {iEvent.getByToken(_hltPixelTracksRegForTau_Tag, PixelTracks_Handle);}  catch (...) {;}

  if(PixelTracks_Handle.isValid()){

    const reco::TrackCollection tracks = *(PixelTracks_Handle.product());
    for(unsigned int i=0; i<tracks.size(); i++) {
      _hltPixelTrack_N++;
      _hltPixelTrack_Pt.push_back(tracks[i].pt());
      _hltPixelTrack_Eta.push_back(tracks[i].eta());
      _hltPixelTrack_Phi.push_back(tracks[i].phi());
    }
  }

  edm::Handle< reco::TrackCollection > MergedTracksTauReg_Handle;
  try {iEvent.getByToken(_hltMergedTracksTauReg_Tag, MergedTracksTauReg_Handle);}  catch (...) {;}

  if(MergedTracksTauReg_Handle.isValid()){
    const reco::TrackCollection tracks = *(MergedTracksTauReg_Handle.product());
    for(unsigned int i=0; i<tracks.size(); i++) {
      _hltMergedTrackTauReg_N++;
      _hltMergedTrackTauReg_Pt.push_back(tracks[i].pt());
      _hltMergedTrackTauReg_Eta.push_back(tracks[i].eta());
      _hltMergedTrackTauReg_Phi.push_back(tracks[i].phi());
    }
  }

  edm::Handle< reco::PFCandidateCollection > PFRegCand_Handle;
  try {iEvent.getByToken(_hltPFRegCand_Tag, PFRegCand_Handle);}  catch (...) {;}

  if(PFRegCand_Handle.isValid()){
    
    const reco::PFCandidateCollection PFRegCands = *(PFRegCand_Handle.product());
    for(size_t i=0; i<PFRegCands.size(); i++){
      
      auto PFRegCand = PFRegCands[i];

      _hltPFRegCand_N++;
      _hltPFRegCand_Pt.push_back(PFRegCand.pt());
      _hltPFRegCand_Eta.push_back(PFRegCand.eta());
      _hltPFRegCand_Phi.push_back(PFRegCand.phi());
    }
  }

  edm::Handle< reco::PFJetCollection > PFJet_Handle;
  try {iEvent.getByToken(_hltAK4PFRegJet_Tag, PFJet_Handle);}  catch (...) {;}

  if(PFJet_Handle.isValid()){
    
    const reco::PFJetCollection PFJets = *(PFJet_Handle.product());
    for(size_t i=0; i<PFJets.size(); i++){
      
      auto PFJet = PFJets[i];

      _hltAK4PFRegJet_N++;
      _hltAK4PFRegJet_Pt.push_back(PFJet.pt());
      _hltAK4PFRegJet_Eta.push_back(PFJet.eta());
      _hltAK4PFRegJet_Phi.push_back(PFJet.phi());
    }
  }


  edm::Handle<reco::CandidateView> jetView;
  edm::Handle<edm::Association<reco::PFJetCollection> > PFJetRegion_Handle;
  edm::Handle<reco::PFJetChargedHadronAssociation> chargedHadronAssoc;
  edm::Handle<reco::JetPiZeroAssociation> piZeroAssoc;

  /*try {iEvent.getByToken(_hltAK4PFRegJet_Tag, jetView);}  catch (...) {;}
  try {iEvent.getByToken(_hltPFJetRegion_Tag, PFJetRegion_Handle);}  catch (...) {;}
  try {iEvent.getByToken(_chargedHadron_token, chargedHadronAssoc);}  catch (...) {;}
  try {iEvent.getByToken(_piZero_token, piZeroAssoc);}  catch (...) {;}*/

  iEvent.getByToken(_jet_token, jetView);
  //iEvent.getByToken(_hltPFJetRegion_Tag, PFJetRegion_Handle);
  iEvent.getByToken(_chargedHadron_token, chargedHadronAssoc);
  iEvent.getByToken(_piZero_token, piZeroAssoc);

  /*
  if(jetView.isValid() && chargedHadronAssoc.isValid() && piZeroAssoc.isValid()){
  
    reco::PFJetRefVector jets = reco::tau::castView<reco::PFJetRefVector>(jetView);

    BOOST_FOREACH( reco::PFJetRef jetRef, jets ) {

      //reco::PFJetRef jetRegionRef = (*PFJetRegion_Handle)[jetRef];
      const std::vector<reco::PFRecoTauChargedHadron>& chargedHadrons = (*chargedHadronAssoc)[jetRef];
      const std::vector<reco::RecoTauPiZero>& piZeros = (*piZeroAssoc)[jetRef];
     
      for(unsigned int i_h=0;i_h<chargedHadrons.size();i_h++){
	_hltTauPFJetsRecoTauChargedHadronsReg_N++;
	_hltTauPFJetsRecoTauChargedHadronsReg_Pt.push_back(chargedHadrons[i_h].pt());
	_hltTauPFJetsRecoTauChargedHadronsReg_Eta.push_back(chargedHadrons[i_h].eta());	
	_hltTauPFJetsRecoTauChargedHadronsReg_Phi.push_back(chargedHadrons[i_h].phi());
      }

      for(unsigned int i_h=0;i_h<piZeros.size();i_h++){
	_hltPFTauPiZerosReg_N++;
	_hltPFTauPiZerosReg_Pt.push_back(piZeros[i_h].pt());
	_hltPFTauPiZerosReg_Eta.push_back(piZeros[i_h].eta());	
	_hltPFTauPiZerosReg_Phi.push_back(piZeros[i_h].phi());
      }   

    }
  }
  */

  edm::Handle< reco::PFTauCollection > PFTauSansRefReg_Handle;
  try {iEvent.getByToken(_hltPFTauSansRefReg_Tag, PFTauSansRefReg_Handle);}  catch (...) {;}

  if(PFTauSansRefReg_Handle.isValid()){
    
    const reco::PFTauCollection PFTaus = *(PFTauSansRefReg_Handle.product());
    for(size_t i=0; i<PFTaus.size(); i++){
      
      auto PFTau = PFTaus[i];

      _hltPFTauSansRefReg_N++;
      _hltPFTauSansRefReg_Pt.push_back(PFTau.pt());
      _hltPFTauSansRefReg_Eta.push_back(PFTau.eta());
      _hltPFTauSansRefReg_Phi.push_back(PFTau.phi());
    }
  }

  this -> _tree -> Fill();

}



bool ZeroBias::hasFilters(const pat::TriggerObjectStandAlone&  obj , const std::vector<std::string>& filtersToLookFor) {

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



Long64_t ZeroBias::FindTriggerBit(const vector<string> foundPaths, const vector<int> indexOfPaths, const edm::Handle<edm::TriggerResults>& triggerResults){
  
  Long64_t bit =0;
 
  for(int it=0;it<(int)_triggerlist.size();it++){
    for(int j=0;j<(int)foundPaths.size();j++){
      
      string toCheckTrigger  = _triggerlist.at(it) ;
      string elemAllTriggers = foundPaths.at(j) ;
      //if(triggerResults->accept(indexOfPaths[j]))
      //cout<<"Path "<<elemAllTriggers<<endl;

      if (elemAllTriggers.find(toCheckTrigger) != std::string::npos) // equivalent to wildcard at the end or beginning of triggername 
      {
	if(triggerResults->accept(indexOfPaths[j]))bit |= long(1) <<it;
	break;
      }
    }
  }
  //printf("bit: %d\n",bit);

  return bit;
}



#include <FWCore/Framework/interface/MakerMacros.h>
DEFINE_FWK_MODULE(ZeroBias);

#endif //ZeroBias_H
