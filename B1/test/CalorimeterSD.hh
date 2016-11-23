//	this is the sensitive detector header file
//	time Mon 14 Nov 2016
//	file name : CalorimeterSD.hh
//

#ifndef SD_HH
#define SD_HH 1

#include "G4VSensitiveDetector.hh"
#include "CalorimeterHit.hh"

#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"

class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

class CalorimeterSD : public G4VSensitiveDetector
{
		private:
				HitsCollection *fHitsCollection;
				G4int fHitsCollectionID;

		public:
				CalorimeterSD( G4String name);
				virtual ~CalorimeterSD();

				virtual void Initialize( G4HCofThisEvent *hce);
				virtual G4bool ProcessHits(G4Step *aStep, G4TouchableHistory *touchable);

};



#endif
