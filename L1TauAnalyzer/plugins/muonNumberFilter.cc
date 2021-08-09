#ifndef MUONNUMBERFILTER_H
#define MUONNUMBERFILTER_H

#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <FWCore/Framework/interface/Frameworkfwd.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/MessageLogger/interface/MessageLogger.h>
#include <FWCore/Utilities/interface/InputTag.h>
#include <DataFormats/PatCandidates/interface/Muon.h>

#include <iostream>

using namespace edm;
using namespace std;
// using namespace reco;

 
class muonNumberFilter : public edm::EDFilter {

    public:
        muonNumberFilter(const edm::ParameterSet &);
        ~muonNumberFilter();

    private:
        bool filter(edm::Event &, edm::EventSetup const&);
        EDGetTokenT<pat::MuonCollection>  _muonTag;
};

muonNumberFilter::muonNumberFilter(const edm::ParameterSet & iConfig) :
_muonTag   (consumes<pat::MuonCollection> (iConfig.getParameter<InputTag>("src")))
{}

muonNumberFilter::~muonNumberFilter()
{}

bool muonNumberFilter::filter(edm::Event & iEvent, edm::EventSetup const& iSetup)
{
    Handle<pat::MuonCollection> muonHandle;
    iEvent.getByToken (_muonTag, muonHandle);

    // very strict - veto all events with > 1 muon
    // if (muonHandle->size() != 1) return false;


    int nmu = 0;
    for (unsigned int imu = 0; imu < muonHandle->size(); imu++)
    {
        const pat::Muon& mu = muonHandle->at(imu);
        float pt = mu.pt();
        float iso = (mu.pfIsolationR04().sumChargedHadronPt + max(mu.pfIsolationR04().sumNeutralHadronEt + mu.pfIsolationR04().sumPhotonEt - 0.5 * mu.pfIsolationR04().sumPUPt, 0.0)) / pt;
	//cout<<"muon pt = "<<pt<<", eta = "<<mu.eta()<<", iso = "<<iso<<", isLoose = "<<mu.isLooseMuon()<<endl;
        if (mu.isLooseMuon() && pt > 10 && fabs(mu.eta()) < 2.4 and iso < 0.3)
            nmu += 1;
    }

    if (nmu > 1)
      {
	//cout<<"does not pass muon veto"<<endl;
	return false;
      }

    //cout<<"does pass muon veto"<<endl;

    return true;

}

#include <FWCore/Framework/interface/MakerMacros.h>
DEFINE_FWK_MODULE(muonNumberFilter);

#endif
