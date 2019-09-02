#ifndef Geometry_TrackerNumberingBuilder_CmsTrackerLevelBuilder_H
#define Geometry_TrackerNumberingBuilder_CmsTrackerLevelBuilder_H

#include "FWCore/ParameterSet/interface/types.h"
#include "Geometry/TrackerNumberingBuilder/interface/CmsTrackerStringToEnum.h"
#include "Geometry/TrackerNumberingBuilder/plugins/CmsTrackerAbstractConstruction.h"
#include <string>

class GeometricDet;

class CmsTrackerLevelBuilderHelper {
public:
  static bool subDetByType(const GeometricDet* a, const GeometricDet* b);
  static bool phiSortNP(const GeometricDet* a, const GeometricDet* b);  // NP** Phase2 BarrelEndcap
  static bool isLessZ(const GeometricDet* a, const GeometricDet* b);
  static bool isLessModZ(const GeometricDet* a, const GeometricDet* b);
  static double getPhi(const GeometricDet* a);
  static double getPhiModule(const GeometricDet* a);
  static double getPhiGluedModule(const GeometricDet* a);
  static double getPhiMirror(const GeometricDet* a);
  static double getPhiModuleMirror(const GeometricDet* a);
  static double getPhiGluedModuleMirror(const GeometricDet* a);
  static bool isLessRModule(const GeometricDet* a, const GeometricDet* b);
  static bool isLessR(const GeometricDet* a, const GeometricDet* b);
};

/**
 * Abstract Class to construct a Level in the hierarchy
 */
template <class T>
class CmsTrackerLevelBuilder : public CmsTrackerAbstractConstruction<T> {
public:
  /* static bool subDetByType(const GeometricDet* a, const GeometricDet* b); */
  /* static bool phiSortNP(const GeometricDet* a, const GeometricDet* b);  // NP** Phase2 BarrelEndcap */
  /* static bool isLessZ(const GeometricDet* a, const GeometricDet* b); */
  /* static bool isLessModZ(const GeometricDet* a, const GeometricDet* b); */
  /* static double getPhi(const GeometricDet* a); */
  /* static double getPhiModule(const GeometricDet* a); */
  /* static double getPhiGluedModule(const GeometricDet* a); */
  /* static double getPhiMirror(const GeometricDet* a); */
  /* static double getPhiModuleMirror(const GeometricDet* a); */
  /* static double getPhiGluedModuleMirror(const GeometricDet* a); */
  /* static bool isLessRModule(const GeometricDet* a, const GeometricDet* b); */
  /* static bool isLessR(const GeometricDet* a, const GeometricDet* b); */

  void build(T&, GeometricDet*, std::string) override;
  ~CmsTrackerLevelBuilder() override {}

private:
  virtual void buildComponent(T&, GeometricDet*, std::string) = 0;

protected:
  CmsTrackerStringToEnum theCmsTrackerStringToEnum;

private:
  virtual void sortNS(T&, GeometricDet*) {}
  CmsTrackerStringToEnum _CmsTrackerStringToEnum;
};

#endif
