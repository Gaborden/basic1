void B220MeV(){
	TCanvas *c1= new TCanvas("c1","",20,20,1000,2000);
	c1->Divide(1,1);
	c1->cd(1);

	TString filename = "B4.root";
	TFile *f =TFile::Open(filename);
	TH1F*h1=new TH1F("Histogram Stat.", "", 400, 100,250);

	TTreeReader r1("B4", f);
	TTreeReaderValue<Double_t> Eabs(r1, "Eabs");
	TTreeReaderValue<Double_t> Egap(r1, "Egap");

	while (r1.Next()){
		h1->Fill(*Eabs + *Egap);
	}
	h1->GetXaxis()->SetTitle("energy (MeV)");
	h1->GetYaxis()->SetTitle("counts");
	h1->SetTitle("220 MeV Incident Beam");
	h1->Draw();
}
