#ifndef GENMATCHTAUFILTER_H
#define GENMATCHTAUFILTER_H

#include "FWCore/Framework/interface/EDFilter.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <FWCore/Framework/interface/Frameworkfwd.h>
#include <FWCore/Framework/interface/Event.h>
#include <FWCore/Framework/interface/ESHandle.h>
#include <FWCore/MessageLogger/interface/MessageLogger.h>
#include <FWCore/Utilities/interface/InputTag.h>
#include <DataFormats/PatCandidates/interface/Tau.h>

#include <iostream>

using namespace edm;
using namespace std;
// using namespace reco;

 
class genMatchTauFilter : public edm::EDFilter {

    public:
        genMatchTauFilter(const edm::ParameterSet &);
        ~genMatchTauFilter();

    private:
        bool filter(edm::Event &, edm::EventSetup const&);
        EDGetTokenT<pat::TauRefVector>  _tauTag;
};

genMatchTauFilter::genMatchTauFilter(const edm::ParameterSet & iConfig) :
_tauTag   (consumes<pat::TauRefVector> (iConfig.getParameter<InputTag>("taus")))
{
    produces <pat::TauRefVector>  ();
}

genMatchTauFilter::~genMatchTauFilter()
{}

bool genMatchTauFilter::filter(edm::Event & iEvent, edm::EventSetup const& iSetup)
{
    std::unique_ptr<pat::TauRefVector>  resultTau  ( new pat::TauRefVector  );
    Handle<pat::TauRefVector> tauHandle;
    iEvent.getByToken (_tauTag, tauHandle);

    int goodTaus = 0;
    for (uint itau = 0; itau < tauHandle->size(); ++itau)
    {
        const pat::TauRef tau = (*tauHandle)[itau] ;    
        if (tau->genJet() && deltaR(tau->p4(), tau->genJet()->p4()) < 0.5 && tau->genJet()->pt() > 8.)
        {
            ++goodTaus;
            resultTau->push_back (tau);
        }
    }
    if (goodTaus == 0) return false;
    
    iEvent.put(std::move(resultTau));

    return true;
}

#include <FWCore/Framework/interface/MakerMacros.h>
DEFINE_FWK_MODULE(genMatchTauFilter);

#endif
