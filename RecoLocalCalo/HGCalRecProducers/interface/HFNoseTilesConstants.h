#ifndef __RecoLocalCalo_HGCalRecAlgos_HFNoseTilesConstants_h__
#define __RecoLocalCalo_HGCalRecAlgos_HFNoseTilesConstants_h__

#include "RecoLocalCalo/HGCalRecProducers/interface/HGCalTilesConstants.h"

#include <cstdint>
#include <array>

struct HFNoseTilesConstants {
  // inner radius ~ 3cm , other radius ~ 110
  static constexpr float tileSize = 5.f;
  static constexpr float minX = -110.f;
  static constexpr float maxX = 110.f;
  static constexpr float minY = -110.f;
  static constexpr float maxY = 110.f;
  static constexpr int nColumns = static_cast<int>(std::ceil((maxX - minX) / tileSize));
  static constexpr int nRows = static_cast<int>(std::ceil((maxY - minY) / tileSize));
  static constexpr float tileSizeEtaPhi = 0.15f;
  static constexpr float minEta = -4.2f;
  static constexpr float maxEta = 4.2f;
  //To properly construct search box for cells in phi=[-3.15,-3.] and [3.,3.15], cells in phi=[3.,3.15] are copied to the first bin and cells in phi=[-3.15,-3.] are copied to the last bin
  static constexpr float minPhi = -3.3f;
  static constexpr float maxPhi = 3.3f;
  static constexpr int nColumnsEta = static_cast<int>(std::ceil((maxEta - minEta) / tileSizeEtaPhi));
  static constexpr int nRowsPhi = static_cast<int>(std::ceil((maxPhi - minPhi) / tileSizeEtaPhi));
  static constexpr int nTiles = nColumns * nRows + nColumnsEta * nRowsPhi;
};

#endif
