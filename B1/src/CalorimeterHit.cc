//	first hit code;
//	time Sun 13 Nov 2016
//	CalorimeterHit.cc
//

#include "CalorimeterHit.hh"
#include "B1DetectorConstruction.hh"

#include "G4ios.hh"
#include "G4Allocator.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"


G4ThreadLocal G4Allocator<CalorimeterHit>* HitAllocator = 0;

CalorimeterHit::CalorimeterHit() : G4VHit(),fColumnID(-1),fRowID(-1),fEdep(0.),fPos(0)
{}

CalorimeterHit::CalorimeterHit(G4int col, G4int row) : G4VHit(),fColumnID(col),fRowID(row),fEdep(0.),fPos(0)
{}

CalorimeterHit::~CalorimeterHit()
{}

CalorimeterHit::CalorimeterHit(const CalorimeterHit &right) : G4VHit()
{
		fColumnID = right.fColumnID;
		fRowID	  = right.fRowID;
		fEdep     = right.fEdep;
		fPos	  = right.fPos;
}

const CalorimeterHit& CalorimeterHit::operator=(const CalorimeterHit &right)
{
		fColumnID = right.fColumnID;
		fRowID	  = right.fRowID;
		fEdep	  = right.fEdep;
		fPos	  = right.fPos;
		return *this;
}

int CalorimeterHit::operator==(const CalorimeterHit &right) const
{
		return (fColumnID==right.fColumnID && fRowID==right.fRowID);
}

void CalorimeterHit::Print()
{
		G4cout<<"	The Calorimeter ID : ["<<fColumnID<<","<<fRowID<<"]"<<G4endl;
		G4cout<<"	The Energy deposit : "<<G4BestUnit(fEdep,"Energy")<<G4endl;
		G4cout<<"	The Position : "<<fPos<<G4endl;
}
