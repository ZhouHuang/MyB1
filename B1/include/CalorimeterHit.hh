//	this is the first hits header file
//	time : Sun 13 Nov 2016
//

#ifndef HIT_H
#define HIT_H 1

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"

class CalorimeterHit : public G4VHit
{
		public :
				CalorimeterHit();
				CalorimeterHit(G4int col, G4int row);
				CalorimeterHit(const CalorimeterHit &right);
				virtual ~CalorimeterHit();

				//	some set and get methods
				//
				void setColumnID(G4int iColID) { fColumnID = iColID;}
				G4int getColumnID() const { return fColumnID;}

				void setRowID(G4int iRowID) {fRowID = iRowID;}
				G4int getRowID() const { return fRowID;}
				
				void setPos(G4ThreeVector iPos) { fPos = iPos;}
				G4ThreeVector getPos() const { return fPos;}

				void setEdep(G4double iEdep) { fEdep = iEdep;}
				void addEdep(G4double ie) {fEdep += ie;}
				G4double getEdep() const { return fEdep;}

				const CalorimeterHit& operator=(const CalorimeterHit &right);
				int operator==(const CalorimeterHit &right) const ;
				inline void *operator new( size_t );
				inline void operator delete( void *aHit);

				//virtual void Draw();
				virtual void Print();

		private:
				G4int fColumnID;
				G4int fRowID;
				G4double fEdep;
				G4ThreeVector fPos;

};


typedef G4THitsCollection<CalorimeterHit> HitsCollection; 

extern G4ThreadLocal G4Allocator<CalorimeterHit>* HitAllocator;

inline void* CalorimeterHit::operator new (size_t)
{
		if ( !HitAllocator)
		{
				HitAllocator = new G4Allocator<CalorimeterHit>;
		}
		return (void*)HitAllocator->MallocSingle();
}

inline void CalorimeterHit::operator delete( void *aHit )
{
		HitAllocator->FreeSingle( (CalorimeterHit*) aHit);
}

#endif
