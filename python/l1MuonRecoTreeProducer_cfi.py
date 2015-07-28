import FWCore.ParameterSet.Config as cms

l1MuonRecoTreeProducer = cms.EDAnalyzer("L1MuonRecoTreeProducer",
  maxMuon = cms.uint32(100),
  muonTag = cms.InputTag("muons"),

  maxRcpHit = cms.uint32(100),
  rpcHitTag = cms.InputTag("rpcRecHits"),

  runOnPostLS1 = cms.bool(True),

  #---------------------------------------------------------------------
  # TRIGGER MATCHING CONFIGURATION
  #---------------------------------------------------------------------
  # flag to turn trigger matching on / off
  triggerMatching = cms.untracked.bool(True),
  # maximum delta R between trigger object and muon
  triggerMaxDeltaR = cms.double(.1),
  # trigger to match to, may use regexp wildcard as supported by ROOT's 
  # TString; up to now the first found match (per run) is used.
  isoTriggerNames = cms.vstring(
        "HLT_IsoMu17_eta2p1_v*",
        "HLT_IsoMu17_v*"
        "HLT_IsoMu20_eta2p1_v*",
        "HLT_IsoMu20_v*"
        "HLT_IsoMu24_eta2p1_v*",
        "HLT_IsoMu24_v*"
        "HLT_IsoMu27_eta2p1_v*",
        "HLT_IsoMu27_v*"
        ),
  triggerNames = cms.vstring(
        "HLT_Mu8_v*",
        "HLT_Mu17_v*",
        "HLT_Mu20_v*",
        "HLT_Mu24_v*",
        "HLT_Mu27_v*",
        "HLT_Mu30_v*",
        "HLT_Mu34_v*",
        "HLT_Mu40_v*",
        "HLT_L1SingleMu*"
        ),

  # data best guess: change for MC!
  triggerSummaryLabel = cms.InputTag("hltTriggerSummaryAOD", "", "HLT"),
  # name of the hlt process (same as above):
  triggerProcessLabel = cms.untracked.string("HLT"),
)

