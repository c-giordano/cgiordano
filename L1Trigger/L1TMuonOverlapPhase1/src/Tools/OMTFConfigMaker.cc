#include "L1Trigger/L1TMuonOverlapPhase1/interface/Omtf/OMTFinput.h"
#include "L1Trigger/L1TMuonOverlapPhase1/interface/Tools/OMTFConfigMaker.h"

#include <iostream>
#include <stdexcept>
#include <vector>

///////////////////////////////////////////////
///////////////////////////////////////////////
OMTFConfigMaker::OMTFConfigMaker(OMTFConfiguration* omtfConfig) : myOmtfConfig(omtfConfig) {
  std::vector<int> refPhi1D(myOmtfConfig->nLogicRegions(), 2 * myOmtfConfig->nPhiBins());
  minRefPhi2D.assign(myOmtfConfig->nRefLayers(), refPhi1D);

  refPhi1D = std::vector<int>(myOmtfConfig->nLogicRegions(), -2 * myOmtfConfig->nPhiBins());
  maxRefPhi2D.assign(myOmtfConfig->nRefLayers(), refPhi1D);
}
///////////////////////////////////////////////
///////////////////////////////////////////////
OMTFConfigMaker::~OMTFConfigMaker() {}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillCounts(unsigned int iProcessor, const OMTFinput& aInput) {}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillPhiMaps(unsigned int iProcessor, const OMTFinput& aInput) {
  ////Find starting and ending iPhi of each input used for reference hits.
  //TODO correct if it is needed
  /*  for(unsigned int iRefLayer=0;iRefLayer<myOmtfConfig->nRefLayers();++iRefLayer){
    const OMTFinput::vector1D & refLayerHits = aInput.getLayerData(myOmtfConfig->getRefToLogicNumber()[iRefLayer]);	
    if(refLayerHits.empty()) continue;
    for(unsigned int iInput=0;iInput<myOmtfConfig->nInputs();++iInput){	
      int phiRef = refLayerHits[iInput];
      unsigned int iRegion = myOmtfConfig->getRegionNumberFromMap(iInput,iRefLayer,phiRef);       
      if(phiRef>=(int)myOmtfConfig->nPhiBins()) continue;      
      if(phiRef<minRefPhi2D[iRefLayer][iRegion]) minRefPhi2D[iRefLayer][iRegion] = phiRef;      
      if(phiRef>maxRefPhi2D[iRefLayer][iRegion]) maxRefPhi2D[iRefLayer][iRegion] = phiRef;      
    }
  }*/
  throw std::runtime_error("OMTFConfigMaker::fillPhiMaps not implemented");
  //TODO implement
}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::printPhiMap(std::ostream& out) {
  out << "min Phi in each logicRegion (X) in each ref Layer (Y): " << std::endl;
  for (unsigned int iRefLayer = 0; iRefLayer < myOmtfConfig->nRefLayers(); ++iRefLayer) {
    for (unsigned int iLogicRegion = 0; iLogicRegion < myOmtfConfig->nLogicRegions(); ++iLogicRegion) {
      out << "          " << minRefPhi2D[iRefLayer][iLogicRegion] << "\t";
    }
    out << std::endl;
  }
  out << std::endl;

  out << "max Phi in each logicRegion (X) in each ref Layer (Y): " << std::endl;
  for (unsigned int iRefLayer = 0; iRefLayer < myOmtfConfig->nRefLayers(); ++iRefLayer) {
    for (unsigned int iLogicRegion = 0; iLogicRegion < myOmtfConfig->nLogicRegions(); ++iLogicRegion) {
      out << "          " << maxRefPhi2D[iRefLayer][iLogicRegion] << "\t";
    }
    out << std::endl;
  }
  out << std::endl;
}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::makeConnetionsMap(unsigned int iProcessor, const OMTFinput& aInput) {
  //TODO correct if it is needed
  /*  fillPhiMaps(iProcessor,aInput);
  
  for(unsigned int iRefLayer=0;iRefLayer<myOmtfConfig->nRefLayers();++iRefLayer){
    const OMTFinput::vector1D & refLayerHits = aInput.getLayerData(myOmtfConfig->getRefToLogicNumber()[iRefLayer]);    
    if(refLayerHits.empty()) continue;
    //////////////////////
    for(unsigned int iInput=0;iInput<refLayerHits.size();++iInput){
      int phiRef = refLayerHits[iInput];
      unsigned int iRegion = myOmtfConfig->getRegionNumberFromMap(iInput,iRefLayer,phiRef);     
      if(iRegion>=myOmtfConfig->nLogicRegions()) continue;      
      fillInputRange(iProcessor,iRegion,aInput);
      fillInputRange(iProcessor,iRegion,iRefLayer,iInput);
      ///Always use two hits from a single chamber. 
      ///As we use single muons, the second hit has
      ///to be added by hand.
      if(iInput%2==0) fillInputRange(iProcessor,iRegion,iRefLayer,iInput+1);
    }      
  }*/
  throw std::runtime_error("OMTFConfigMaker::fillPhiMaps not implemented");
  //TODO implement
}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillInputRange(unsigned int iProcessor, unsigned int iRegion, const OMTFinput& aInput) {
  /*  for(unsigned int iLogicLayer=0;iLogicLayer<myOmtfConfig->nLayers();++iLogicLayer){
    for(unsigned int iInput=0;iInput<myOmtfConfig->nInputs();++iInput){
      bool isHit = aInput.getLayerData(iLogicLayer)[iInput]<(int)myOmtfConfig->nPhiBins();
      myOmtfConfig->getMeasurements4D()[iProcessor][iRegion][iLogicLayer][iInput]+=isHit;
    }
  }*/
  throw std::runtime_error("OMTFConfigMaker::fillPhiMaps not implemented");
  //TODO implement
}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::fillInputRange(unsigned int iProcessor,
                                     unsigned int iRegion,
                                     unsigned int iRefLayer,
                                     unsigned int iInput) {
  ++myOmtfConfig->getMeasurements4Dref()[iProcessor][iRegion][iRefLayer][iInput];
}
///////////////////////////////////////////////
///////////////////////////////////////////////
void OMTFConfigMaker::printConnections(std::ostream& out, unsigned int iProcessor, unsigned int iRegion) {
  out << "iProcessor: " << iProcessor << " iRegion: " << iRegion << std::endl;

  out << "Ref hits" << std::endl;
  for (unsigned int iLogicLayer = 0; iLogicLayer < myOmtfConfig->nLayers(); ++iLogicLayer) {
    out << "Logic layer: " << iLogicLayer << " Hits: ";
    for (unsigned int iInput = 0; iInput < myOmtfConfig->nInputs(); ++iInput) {
      out << myOmtfConfig->getMeasurements4Dref()[iProcessor][iRegion][iLogicLayer][iInput] << "\t";
    }
    out << std::endl;
  }
  /*
  out<<"Measurement hits"<<std::endl;
  for(unsigned int iLogicLayer=0;iLogicLayer<myOmtfConfig->nLayers();++iLogicLayer){
    out<<"Logic layer: "<<iLogicLayer<<" Hits: ";
    for(unsigned int iInput=0;iInput<myOmtfConfig->nInputs();++iInput){
      out<<myOmtfConfig->getMeasurements4D()[iProcessor][iRegion][iLogicLayer][iInput]<<"\t";
    }
    out<<std::endl;
  }
  */
  out << std::endl;
}
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
