//////////////////////////////////////
// Example root macro for l1 ntuples
//////////////////////////////////////

#ifndef L1Ntuple_h
#define L1Ntuple_h

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <TFriendElement.h>
#include <TList.h>
#include <TMatrix.h>
#include <TH1D.h>
#include <TH1F.h>
#include <TH2D.h>
#include <TH2F.h>
#include <TCanvas.h>

#include "L1AnalysisEventDataFormat.h"
#include "L1AnalysisSimulationDataFormat.h"
#include "L1AnalysisGCTDataFormat.h"
#include "L1AnalysisGTDataFormat.h"
#include "L1AnalysisGMTDataFormat.h"
#include "L1AnalysisGTDataFormat.h"
#include "L1AnalysisRCTDataFormat.h"
#include "L1AnalysisDTTFDataFormat.h"
#include "L1AnalysisCSCTFDataFormat.h"
#include "L1AnalysisRecoMetDataFormat.h"
#include "L1AnalysisRecoJetDataFormat.h"
#include "L1AnalysisRecoClusterDataFormat.h"
#include "L1AnalysisRecoMuonDataFormat.h"
#include "L1AnalysisRecoRpcHitDataFormat.h"
#include "L1AnalysisL1ExtraDataFormat.h"
#include "L1AnalysisRecoVertexDataFormat.h"
#include "L1AnalysisRecoTrackDataFormat.h"
#include "L1AnalysisL1MenuDataFormat.h"

class L1Ntuple {
public:
  TChain          *fChain;   //!pointer to the analyzed TTree or TChain
  TChain          *ftreemuon;
  TChain          *ftreereco;
  TChain          *ftreeExtra;
  TChain          *ftreeMenu;
  TChain          *ftreeEmuExtra;
  Int_t            fCurrent; //!current Tree number in a TChain

  bool doreco;
  bool domuonreco;
  bool dol1extra;
  bool dol1emuextra;
  bool dol1menu;

  L1Analysis::L1AnalysisEventDataFormat        *event_;
  L1Analysis::L1AnalysisSimulationDataFormat   *simulation_;
  L1Analysis::L1AnalysisGCTDataFormat          *gct_;
  L1Analysis::L1AnalysisGMTDataFormat          *gmt_;
  L1Analysis::L1AnalysisGTDataFormat           *gt_;
  L1Analysis::L1AnalysisRCTDataFormat          *rct_;
  L1Analysis::L1AnalysisDTTFDataFormat         *dttf_;
  L1Analysis::L1AnalysisCSCTFDataFormat        *csctf_;
  L1Analysis::L1AnalysisRecoMetDataFormat      *recoMet_;
  L1Analysis::L1AnalysisRecoMuonDataFormat     *recoMuon_;
  L1Analysis::L1AnalysisRecoRpcHitDataFormat   *recoRpcHit_;
  L1Analysis::L1AnalysisRecoJetDataFormat      *recoJet_;
  L1Analysis::L1AnalysisRecoClusterDataFormat  *recoBasicCluster_;
  L1Analysis::L1AnalysisRecoClusterDataFormat  *recoSuperCluster_;
  L1Analysis::L1AnalysisL1ExtraDataFormat      *l1extra_;
  L1Analysis::L1AnalysisL1ExtraDataFormat      *l1emuextra_;
  L1Analysis::L1AnalysisRecoVertexDataFormat   *recoVertex_;
  L1Analysis::L1AnalysisRecoTrackDataFormat    *recoTrack_;
  L1Analysis::L1AnalysisL1MenuDataFormat       *l1menu_;

  L1Ntuple();
  L1Ntuple(const std::string & fname);

  virtual ~L1Ntuple();

  bool Open(const std::string & fname);
  bool OpenWithList(const std::string & fname);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init();
  //virtual void     Loop();
  void     Test();
  void     Test2();
  Long64_t GetEntries();

 private :
  bool CheckFirstFile();
  bool OpenWithoutInit();
  bool OpenNtupleList(const std::string & fname);

  std::vector<std::string> listNtuples;
  Long64_t nentries_;
  TFile* rf;
};

#endif
