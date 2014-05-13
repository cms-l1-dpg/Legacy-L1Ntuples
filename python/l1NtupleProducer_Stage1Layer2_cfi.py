import FWCore.ParameterSet.Config as cms

import L1TriggerDPG.L1Ntuples.l1NtupleProducer_cfi
l1NtupleProducer = L1TriggerDPG.L1Ntuples.l1NtupleProducer_cfi.l1NtupleProducer.clone()

l1NtupleProducer.gctCentralJetsSource = cms.InputTag("Layer2gctFormat","cenJets")
l1NtupleProducer.gctNonIsoEmSource    = cms.InputTag("Layer2gctFormat","nonIsoEm")
l1NtupleProducer.gctForwardJetsSource = cms.InputTag("Layer2gctFormat","forJets")
l1NtupleProducer.gctIsoEmSource       = cms.InputTag("Layer2gctFormat","isoEm")
l1NtupleProducer.gctEnergySumsSource  = cms.InputTag("Layer2gctFormat","")
l1NtupleProducer.gctTauJetsSource     = cms.InputTag("Layer2gctFormat","tauJets")
l1NtupleProducer.rctSource            = cms.InputTag("Layer2gctFormat")

