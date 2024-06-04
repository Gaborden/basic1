void B30(){
	TCanvas *c1= new TCanvas("c1","",20,20,1000,1000);
	c1->Divide(2,3);

	TString filename= "~/opt/basic/B5/B5ntuple.root";
	TFile*f = TFile::Open(filename);

	TH1F*h1 = new TH1F("Dc1 Hits","",400,0,70);
	TH1F*h2 = new TH1F("Dc2 Hits","",400,0,50);
	TH1F*h3 = new TH1F("ECEnergy","",400,-20,200);
	TH1F*h4 = new TH1F("HCEnergy","",400,-20,20);
	TH1F*h5 = new TH1F("Times1","",400,0,40);
	TH1F*h6 = new TH1F("Times2","",400,-10,80);
	TH1F*h7 = new TH1F("ECEnergyVector","",400,0,200);
	TH1F*h8 = new TH1F("HCEnergyVector","",400,0,200);

	TTreeReader r1("B5", f);
	TTreeReaderValue<int> Dc1Hits (r1, "Dc1Hits");
	TTreeReaderValue<Int_t> Dc2Hits (r1, "Dc2Hits");
	TTreeReaderValue<Double_t> ECEnergy (r1, "ECEnergy");
	TTreeReaderValue<Double_t> HCEnergy (r1, "HCEnergy");
	TTreeReaderValue<Double_t> Time1 (r1, "Time1");
	TTreeReaderValue<Double_t> Time2 (r1, "Time2");
	//TTreeReaderValue<Int_t> ECEnergyVector (r1, "ECEnergyVector");
	//TTreeReaderValue<Int_t> HCEnergyVector (r1, "HCEnergyVector");


	while (r1.Next()){
		h1->Fill(*Dc1Hits);
		h2->Fill(*Dc2Hits);
		h3->Fill(*ECEnergy);
		h4->Fill(*HCEnergy);
		h5->Fill(*Time1);
		h6->Fill(*Time2);
		//h7->Fill(*ECEnergyVector);
		//h8->Fill(*HCEnergyVector);
	}
	c1->cd(1);
	h1->GetXaxis()->SetTitle("x-axis");
	h1->GetXaxis()->CenterTitle();
	h1->GetYaxis()->SetTitle("y-axis");
	h1->GetYaxis()->CenterTitle();
	h1->SetTitle("Dc1Hits");
	h1->SetLineColor(1);
	h1->Draw();
	
	c1->cd(2);
	h2->GetXaxis()->SetTitle("x-axis");
	h2->GetXaxis()->CenterTitle();
	h2->GetYaxis()->SetTitle("y-axis");
	h2->GetYaxis()->CenterTitle();
	h2->SetTitle("Dc2Hits");
	h2->SetLineColor(2);
	h2->Draw();

	c1->cd(3);
	h3->GetXaxis()->SetTitle("x-axis");
	h3->GetXaxis()->CenterTitle();
	h3->GetYaxis()->SetTitle("y-axis");
	h3->GetYaxis()->CenterTitle();
	h3->SetTitle("EC Energy");
	h3->SetLineColor(3);
	h3->Draw();

	c1->cd(4);
	h4->GetXaxis()->SetTitle("x-axis");
	h4->GetXaxis()->CenterTitle();
	h4->GetYaxis()->SetTitle("y-axis");
	h4->GetYaxis()->CenterTitle();
	h4->SetTitle("HC Energy");
	h4->SetLineColor(4);
	h4->Draw();

	c1->cd(5);
	h5->GetXaxis()->SetTitle("x-axis");
	h5->GetXaxis()->CenterTitle();
	h5->GetYaxis()->SetTitle("y-axis");
	h5->GetYaxis()->CenterTitle();
	h5->SetTitle("Time 1");
	h5->SetLineColor(5);
	h5->Draw();

	c1->cd(6);
	h6->GetXaxis()->SetTitle("x-axis");
	h6->GetXaxis()->CenterTitle();
	h6->GetYaxis()->SetTitle("y-axis");
	h6->GetYaxis()->CenterTitle();
	h6->SetTitle("Time 2");
	h6->SetLineColor(6);
	h6->Draw();

	/*c1->cd(7);
	h7->GetXaxis()->SetTitle("x-axis");
	h7->GetYaxis()->SetTitle("y-axis");
	h7->SetTitle("EC Energy Vector");
	h7->Draw();*/

	//c1->cd(8);
	//h8->GetXaxis()->SetTitle("x-axis");
	//h8->GetYaxis()->SetTitle("y-axis");
	//h8->SetTitle("HC Energy Vector");
	//h8->Draw();

}
