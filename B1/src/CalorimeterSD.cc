//	this is the sensitive detector source file
//	time Mon 14 Nov 2016
//	file name : CalorimeterSD.cc
//

#include "CalorimeterSD.hh"
#include "CalorimeterHit.hh"

#include "G4ios.hh"
#include "G4SDManager.hh"

CalorimeterSD::CalorimeterSD(G4String name) : G4VSensitiveDetector(name),fHitsCollection(0),fHitsCollectionID(-1)
{
		collectionName.insert("calorimeter hits collection");
}

CalorimeterSD::~CalorimeterSD()
{}

void CalorimeterSD::Initialize(G4HCofThisEvent *hce)
{
		fHitsCollection =
				new HitsCollection(SensitiveDetectorName,collectionName[0]);
		if (fHitsCollectionID < 0)
		{
				fHitsCollectionID = 
						G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
		}
		hce->AddHitsCollection(fHitsCollectionID,fHitsCollection);

		//	related to the physic volume
		for (G4int icol=0;icol<2;icol++)
		{
				for(G4int irow=0;irow<2;irow++)
				{
						CalorimeterHit* hit = new CalorimeterHit();
						fHitsCollection->insert(hit);
				}
		}
		

		//
		//

}

G4bool CalorimeterSD::ProcessHits(G4Step *aStep, G4TouchableHistory* )
{
		G4double edep = aStep->GetTotalEnergyDeposit();

		if(edep ==0) return true;

		G4StepPoint* prePoint = aStep->GetPreStepPoint();

		G4TouchableHistory* touchable = (G4TouchableHistory*)(prePoint->GetTouchable());

		G4int rowNo = touchable->GetCopyNumber(2);
		G4int colNo = touchable->GetCopyNumber(3);
		G4int hitID = 2*rowNo + colNo;
		
		//CalorimeterHit* hit = new CalorimeterHit(colNo,rowNo);

		CalorimeterHit* hit = (*fHitsCollection)[hitID];
		//
		if(hit->getColumnID() < 0)
		{
				hit->setColumnID(colNo);
				hit->setRowID(rowNo);
		}

		hit->addEdep(edep);
		return true;
	




		/*
		G4int cpNum = touchable->GetVolume()->GetCopyNo();

		G4int ix=-1;
		for( G4int i=0; i<fHitsCollection->entries();i++)
		{
				if (fHitsCollection[i]->GetCopyNo == cpNum)
				{
						ix = i;
						break;
				}
		}

		if (ix < 0 )
		{
				CalorimeterHit* hit = new CalorimeterHit(cpNum);
				fHitsCollection->insert(hit);
		}
		*/

}

