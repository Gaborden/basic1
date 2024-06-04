void IB500Mev(){
	TCanvas *c1 = new TCanvas("c1","",20,20,1000,1000);
	c1->Divide(1,1);
	c1->cd(1);

	TString filename ="B4.root";
	TFile*F=TFile::Open(filename);

	TH1F*h1=new TH1F ("Histogram","",400,400,600);

	TTreeReader r1("B4",F);
	TTreeReaderValue<Double_t> Eabs(r1, "Eabs");
	TTreeReaderValue<Double_t> Egap(r1, "Egap");

	while(r1.Next()){
		h1->Fill(*Eabs + *Egap);
	}

	h1->GetXaxis()->SetTitle("Energy (Mev)");
	h1->GetYaxis()->SetTitle("Counts");
	h1->SetTitle("500Mev Incident Beam");
	h1->Draw();
}
