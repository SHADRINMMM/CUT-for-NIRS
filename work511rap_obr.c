#include <iostream>
#include <cmath>
using namespace std;
void work511rap_obr (){

const double lumi_for_calc_a=36214.96;
const int nbins = 6;	
  TFile* f1= new TFile("MCData16a.root", "READ"); //данные 
  TTree *tree1 = (TTree*)f1->Get("output_tree"); 
  //auto tree_sw = (TTree*)f1->Get("output_tree_sw");
  //auto tree_norm = (TTree*)f1->Get("norm_tree");
  TTree *tree_sw = (TTree*)f1->Get("output_tree_sw");
  TTree *tree_norm = (TTree*)f1->Get("norm_tree");
  TFile* f2= new TFile("MCData16.root", "READ");//фон
  auto tree2 = (TTree*)f2->Get("output_tree");
  
  //гистограммы для распеделения по событиям с определенными значениями критерия 
  //для сигнала
  TH1F *Hist_pt_S = new TH1F("Pt_balance", "Entries&Pt_balance;Pt-balabnce ;Entries", 19, 0, 1.0);
  TH1F *Hist_centr_S = new TH1F("zet", "centrality;centrality;Entries", 50, 0, 15);
  TH1F *Hist_mass_S = new TH1F("Pt_balance", "Entries&Pt_balance;Pt-balabnce ;Entries", 50, 0, 1.0);
  TH1F *Hist_rap_S = new TH1F("zet", "rapidity;P_{T} [GeV];Entries", 100, 0, 1.0);
  
  //для форна
  TH1F *Hist_pt_B = new TH1F("Pt_balance", "Entries&Pt_balance;Pt-balabnce;Entries", 19, 0,1.0);
  TH1F *Hist_centr_B = new TH1F("zet", "centrality;centrality;Entries", 50, 0, 15);
  TH1F *Hist_mass_B = new TH1F("Pt_balance", "Entries&Pt_balance;Pt-balabnce;Entries", 50, 0,1.0);
  TH1F *Hist_rap_B = new TH1F("zet", "rapidity;P_{T} [GeV];Entries", 100, 0, 1.0);
  
  //для значимостей
  TH1F *Hist_zn_pt= new TH1F("importance of kriteria of pt-balabnce", "importance&level;level[GeV]; importance;",19, 0,1.0);
  TH1F *Hist_zn_centr= new TH1F("importance of kriteria of centrality", "importance&level;level[GeV]; importance;", 19, 0,2);
  TH1F *Hist_zn_mass= new TH1F("importance of kriteria of mass", "importance&level;level[GeV]; importance;", 19, 0,1.0);
  TH1F *Hist_zn_rap= new TH1F("importance of kriteria of rap", "importance&level;level[GeV]; importance;", 101, 0,1.0);
  
  
  TH1D *cutflow1 = new TH1D("cutflow", "Number of accepted events", nbins, 1, nbins + 1);
  cutflow1->GetXaxis()->SetBinLabel(1, "All");
  cutflow1->GetXaxis()->SetBinLabel(2, "pt_ph_S > 150");
  cutflow1->GetXaxis()->SetBinLabel(3, "pt_met_S> 130");
  cutflow1->GetXaxis()->SetBinLabel(4, "N_jets_S>=2");
  
  TH1D *cutflow2 = new TH1D("cutflow", "Number of accepted events", nbins, 1, nbins + 1);
  cutflow2->GetXaxis()->SetBinLabel(1, "All");
  cutflow2->GetXaxis()->SetBinLabel(2, "pt_ph_S > 150");
  cutflow2->GetXaxis()->SetBinLabel(3, "pt_met_S> 130");
  cutflow2->GetXaxis()->SetBinLabel(4, "N_jets_S>=2");
  
  TH1D *cutflow = new TH1D("cutflow", "Number of accepted events", nbins, 1, nbins + 1);
  cutflow->GetXaxis()->SetBinLabel(1, "All");
  TH1D *cutfloww = new TH1D("cutflow", "Number of accepted events", nbins, 1, nbins + 1);
  cutfloww->GetXaxis()->SetBinLabel(1, "All");

  
  TH1D *cutflow_S = new TH1D("cutflow", "Number events with kriteria for signal", nbins, 1, nbins + 1);
  cutflow_S->GetXaxis()->SetBinLabel(1, "All");
  cutflow_S->GetXaxis()->SetBinLabel(2, "mjj");
  cutflow_S->GetXaxis()->SetBinLabel(3, "Rapidity");
  cutflow_S->GetXaxis()->SetBinLabel(4, "centr");
  cutflow_S->GetXaxis()->SetBinLabel(5, "pt balance");
  
  TH1D *cutflow_B = new TH1D("cutflow", "Number events with kriteria for background", nbins, 1, nbins + 1);
  cutflow_B->GetXaxis()->SetBinLabel(1, "All");
  cutflow_B->GetXaxis()->SetBinLabel(2, "mjj");
  cutflow_B->GetXaxis()->SetBinLabel(3, "Rapidity");
  cutflow_B->GetXaxis()->SetBinLabel(4, "centr");
  cutflow_B->GetXaxis()->SetBinLabel(5, "pt balance");
  
  
  
  TCanvas *c = new TCanvas("c","",1900,1900);
  c->Divide(2);
   /*
   Hist_zn_pt->SetDirectory(gROOT);
   Hist_zn_mass->SetDirectory(gROOT);
   Hist_zn_rap->SetDirectory(gROOT);
   Hist_zn_centr->SetDirectory(gROOT);
  */
  cutflow_S->SetDirectory(gROOT);
  cutflow_B->SetDirectory(gROOT);
  cutflow->SetDirectory(gROOT);
  cutflow1->SetDirectory(gROOT);
  
  TCanvas *b = new TCanvas("b","",1900,1900);
  b->Divide(2);  
  b->SetLogy(3);
    Hist_zn_pt->SetDirectory(gROOT);
   Hist_zn_mass->SetDirectory(gROOT);
   Hist_zn_rap->SetDirectory(gROOT);
   Hist_zn_centr->SetDirectory(gROOT);
	Hist_zn_pt->SetDirectory(gROOT);
   Hist_pt_S->SetDirectory(gROOT);
   Hist_pt_B->SetDirectory(gROOT);
   Hist_centr_S->SetDirectory(gROOT);
   Hist_centr_B->SetDirectory(gROOT);
   Hist_mass_S->SetDirectory(gROOT);
   Hist_mass_B->SetDirectory(gROOT);
   Hist_rap_S->SetDirectory(gROOT);
   Hist_rap_B->SetDirectory(gROOT);
   
   
  // 4 вектора в которые будут составляться из дерева 
// с индексом _S - собыите  
   TLorentzVector lead_S  ;
   TLorentzVector sub_lead_S ;
   TLorentzVector ph_S ;
   TLorentzVector met_S ;
   
   TLorentzVector lead_B  ;
   TLorentzVector sub_lead_B ;
   TLorentzVector ph_B ;
   TLorentzVector met_B ;
   //задание переменных 
   Double_t norm_koef=0;
    Double_t sum_of_weights=0;
   Double_t pt_lead_S=0;
   Double_t pt_lead_B=0;
   Double_t pt_sublead_B=0;
   Double_t pt_sublead_S=0;
   
   Double_t pt_met_B=0;
   Double_t pt_met_S=0;
   Double_t pt_ph_B=0;
   Double_t pt_ph_S=0 ;
   
   Double_t eta_lead_S=0;
   Double_t eta_lead_B=0;
   Double_t eta_sublead_S=0;
   Double_t eta_sublead_B=0;
   
   Double_t eta_ph_S=0;
   Double_t eta_ph_B=0;
   
   Double_t phi_lead_S=0;
   Double_t phi_lead_B=0;
   Double_t phi_sublead_S=0;
   Double_t phi_sublead_B=0;
   
   Double_t phi_met_S=0;
   Double_t phi_met_B=0;
   
   Double_t phi_ph_S=0;
   Double_t phi_ph_B=0;
   
   Double_t E_lead_S=0;
   Double_t E_lead_B=0;
   
   Double_t E_sublead_S=0;
   Double_t E_sublead_B=0;
   
   Double_t weight_S=0;
   Double_t weight_B=0;
   
   UInt_t N_jets_B=0;
   UInt_t N_jets_S=0;
  
  
 // cчитывание данных из дерева 
	tree_norm->SetBranchAddress("koef",&norm_koef);
	tree_sw-> SetBranchAddress ( "sum_of_weights_bk_xAOD" , &sum_of_weights);

	tree1-> SetBranchAddress ( "weight" , &weight_S);
    tree2-> SetBranchAddress ( "weight" , &weight_B);
	
   tree1-> SetBranchAddress ( "jet_lead_pt" , &pt_lead_S);
   tree1-> SetBranchAddress ( "jet_lead_eta" , &eta_lead_S);
   tree1-> SetBranchAddress ( "jet_lead_phi" , &phi_lead_S);
   tree1-> SetBranchAddress ( "jet_lead_E" , &E_lead_S);
   
   tree2-> SetBranchAddress ( "jet_lead_pt" , &pt_lead_B);
   tree2-> SetBranchAddress ( "jet_lead_eta" , &eta_lead_B);
   tree2-> SetBranchAddress ( "jet_lead_phi" , &phi_lead_B);
   tree2-> SetBranchAddress ( "jet_lead_E" , &E_lead_B);
   
   tree1-> SetBranchAddress ( "jet_sublead_pt" , &pt_sublead_S);
   tree1-> SetBranchAddress ( "jet_sublead_eta" , &eta_sublead_S);
   tree1-> SetBranchAddress ( "jet_sublead_phi" , &phi_sublead_S);
   tree1-> SetBranchAddress ( "jet_sublead_E" , &E_sublead_S);
   
   tree2-> SetBranchAddress ( "jet_sublead_pt" , &pt_sublead_B);
   tree2-> SetBranchAddress ( "jet_sublead_eta" , &eta_sublead_B);
   tree2-> SetBranchAddress ( "jet_sublead_phi" , &phi_sublead_B);
   tree2-> SetBranchAddress ( "jet_sublead_E" , &E_sublead_B);
   
   tree1-> SetBranchAddress ( "ph_pt" , &pt_ph_S);
   tree1-> SetBranchAddress ( "ph_eta" , &eta_ph_S);
   tree1-> SetBranchAddress ( "ph_phi" , &phi_ph_S);

   
   tree2-> SetBranchAddress ( "ph_pt" , &pt_ph_B);
   tree2-> SetBranchAddress ( "ph_eta" , &eta_ph_B);
   tree2-> SetBranchAddress ( "ph_phi" , &phi_ph_B);

   
   tree1-> SetBranchAddress ( "metTST_pt" , &pt_met_S);
   tree1-> SetBranchAddress ( "metTST_phi" , &phi_met_S);

   
   tree2-> SetBranchAddress ( "metTST_pt" , &pt_met_B);
   tree2-> SetBranchAddress ( "metTST_phi" , &phi_met_B);
   
   tree1-> SetBranchAddress ( "n_jet" , &N_jets_S);
   tree2-> SetBranchAddress ( "n_jet" , &N_jets_B);

   Double_t weight_real_S=0;
   Double_t weight_real_B=0;

   Double_t Kr_S=0;
   Double_t Kr_cetr_S =0;
   Double_t Kr_mass_S =0;
   Double_t Kr_rapidity_S =0;
   Double_t Kr_pt_S =0;

	Double_t Kr_B=0;
	Double_t Kr_cetr_B =0;
	Double_t Kr_mass_B =0;
	Double_t Kr_rapidity_B =0;
	Double_t Kr_pt_B  =0;
 
   Double_t njj_S=0;
   Double_t njj_B=0;
   Double_t dnjj_S=0;
   Double_t dnjj_B=0;
   Double_t zet_S=0;
   Double_t zet_B=0;
   
   Double_t  level_pt=0;
   Double_t  level_mass=0;
   Double_t  level_rap=1.0;
   Double_t  level_centr=0;
   
   Double_t  max_Zn_Kr_pt=0;
   Double_t max_level_pt=0;
   
   Double_t  max_Zn_Kr_mass=0;
   Double_t max_level_mass=0;
   
   Double_t  max_Zn_Kr_cetr=0;
   Double_t max_level_cetr=0;
   
   Double_t  max_Zn_Kr_rap=0;
   Double_t max_level_rap=0;
  //считываение количества вхождений в дерево
   Long64_t nEvents_S = tree1->GetEntries();
   Long64_t nEvents_B = tree2->GetEntries();
   Long64_t nEvents = tree_sw->GetEntries();
   Double_t Zn_Kr_pt =0;
   Double_t Zn_Kr_rapidity =0;
   Double_t Zn_Kr_cetr =0;
   Double_t Zn_Kr_mass =0;
   Double_t PT_BALANCE_S=0;
   Double_t PT_BALANCE_B=0;
   Long64_t p=0;
   int i=0;
   Double_t weight_sum=0;
   for ( Long64_t j = 0; j < nEvents; j++){
     tree_sw->GetEntry(j);
   weight_sum=weight_sum+sum_of_weights;
  
   
   }  
   tree_norm->GetEntry(0);
    Double_t koef_set=norm_koef*lumi_for_calc_a/weight_sum;
	
   // pt-balance
//	while (level_pt<=1){
	// centrality
//	while (level_centr<=1){   
	//mass
	while (level_rap>=0){
	//rapidity
	//while (level_mass<=3000){

    for ( Long64_t j = 0; j < nEvents_S; j++)
		{
	//проверка начальных критериев 
			tree1->GetEntry(j);
			//cutflow->Fill(1);
			//cutflow1->Fill(1);
	
			if ( !(pt_ph_S > 150) ) continue;  
			cutflow1->Fill(2);
			
			if ( !(pt_met_S> 130) ) continue;  
			cutflow1->Fill(3);

			if ( !(N_jets_S>=2) ) continue;  
			cutflow1->Fill(4);
			
			weight_real_S=weight_S*koef_set;
			//cout<<weight_S;
	// заполнение 4 векторов 
			lead_S.SetPtEtaPhiE(pt_lead_S,eta_lead_S,phi_lead_S,E_lead_S);
			sub_lead_S.SetPtEtaPhiE(pt_sublead_S,eta_sublead_S,phi_sublead_S,E_sublead_S);
			ph_S.SetPtEtaPhiM(pt_ph_S,eta_ph_S,phi_ph_S,0);
			met_S.SetPtEtaPhiM(pt_met_S,0,phi_met_S,0);
	//критерий на инвариантную массу 
	/*
			Kr_S=Kr_S+1;
			//cutflow_S->Fill(1);
			if((lead_S.M()+sub_lead_S.M())>level_mass) Kr_mass_S=Kr_mass_S+weight_real_S;
			//cutflow_S->Fill(2);
	*/
			//кртерий на разность быстрот
	
			if((abs(lead_S.Rapidity()-sub_lead_S.Rapidity()))>level_rap) Kr_rapidity_S=Kr_rapidity_S+weight_real_S;
			Hist_rap_S->Fill(((abs(lead_S.Rapidity()-sub_lead_S.Rapidity()))),weight_real_S);
			
			//cutflow_S->Fill(3);
			
	
	//критерий на центральность 
	/*
			
			njj_S=(lead_S.PseudoRapidity()+sub_lead_S.PseudoRapidity())/2;	
			dnjj_S=(lead_S.PseudoRapidity()-sub_lead_S.PseudoRapidity());
			if (dnjj_S!=0)zet_S=abs((ph_S.PseudoRapidity()-njj_S)/dnjj_S);
			if (dnjj_S==0)zet_B=1000;
			Hist_centr_S->Fill(zet_S*weight_real_S);
		//	cout<<zet_S<<endl<<"kriter="; 
			//cout<<Kr_cetr_S<<"\n";
//			if (zet_S>1000) cout<<"1"<<endl;
			//cout<<level_centr;
			if (zet_S<level_centr){
			
					
				Kr_cetr_S=weight_real_S+Kr_cetr_S;
			}
			//cout<<weight_real_S<<"kriter=";
			//cout<<Kr_cetr_S<<"\n";
			//cutflow_S->Fill(4);
		*/	
		//критерий на pt
	/*
			if((pow(lead_S.Pt(),2)+pow(sub_lead_S.Pt(),2)+pow(ph_S.Pt(),2)+pow(met_S.E(),2))!=0)PT_BALANCE_S=pow(((lead_S+sub_lead_S+ph_S+met_S).Pt()),2)/(pow(lead_S.Pt(),2)+pow(sub_lead_S.Pt(),2)+pow(ph_S.Pt(),2)+pow(met_S.E(),2));
			if((pow(lead_S.Pt(),2)+pow(sub_lead_S.Pt(),2)+pow(ph_S.Pt(),2)+pow(met_S.E(),2))==0)PT_BALANCE_S=1000;
			Hist_pt_S->Fill(PT_BALANCE_S*weight_real_S);
			//if(PT_BALANCE_S>level_pt)
			if(PT_BALANCE_S<level_pt) Kr_pt_S=Kr_pt_S+weight_real_S;
			//cutflow_S->Fill(5);
	
		*/	
		}
  //подсчет значимости для фона   
  for ( Long64_t j = 0; j < nEvents_B; j++)
	  {
	//проверка начальных критериев   
			tree2->GetEntry(j);
			//cutfloww->Fill(1);
			//cutflow2->Fill(1);
			
			weight_real_B=weight_B*koef_set;
			if ( !(pt_ph_B > 150) ) continue;  
			//cutflow2->Fill(2);
			if ( !(pt_met_B> 130) ) continue;  
			//cutflow2->Fill(3);
			if ( !(N_jets_B>=2) ) continue;  
			//cutflow2->Fill(4);	
	
	// заполнение 4 векторов  
			lead_B.SetPtEtaPhiE(pt_lead_B,eta_lead_B,phi_lead_B,E_lead_B);
			sub_lead_B.SetPtEtaPhiE(pt_sublead_B,eta_sublead_B,phi_sublead_B,E_sublead_B);
			ph_B.SetPtEtaPhiM(pt_ph_B,eta_ph_B,phi_ph_B,0);
			met_B.SetPtEtaPhiM(pt_met_B,0,phi_met_B,0);


	//критерий на инвариантную массу 
			//cutflow_B->Fill(1);
	/*
			Kr_B=Kr_B+1;
			if((lead_B.M()+sub_lead_B.M())>level_mass) Kr_mass_B=Kr_mass_B+1;
			cutflow_B->Fill(2);
	*/
	//кртерий на разность быстрот
	
			if((abs(lead_B.Rapidity()-sub_lead_B.Rapidity()))>level_rap) Kr_rapidity_B=Kr_rapidity_B+weight_real_B;
			Hist_rap_B->Fill(abs(lead_B.Rapidity()-sub_lead_B.Rapidity()),weight_real_B);
			//cutflow_B->Fill(3);
	
	//критерий на центральность
/*	
			njj_B=(lead_B.PseudoRapidity()+sub_lead_B.PseudoRapidity())/2;	
			dnjj_B=(lead_B.PseudoRapidity()-sub_lead_B.PseudoRapidity());
			if (dnjj_B!=0) zet_B=abs((ph_B.PseudoRapidity()-njj_B)/dnjj_B);
			if (dnjj_B==0)zet_B=1000;
			Hist_centr_B->Fill(zet_B*weight_real_B);
			if (zet_B<level_centr) Kr_cetr_B=Kr_cetr_B+weight_real_B;
			//cout<< Kr_cetr_B;
			//cutflow_B->Fill(4);
	*/
	//критерий на pt 
	/*
			if((pow(lead_B.Pt(),2)+pow(sub_lead_B.Pt(),2)+pow(ph_B.Pt(),2)+pow(met_B.E(),2))!=0)PT_BALANCE_B=pow(((lead_B+sub_lead_B+ph_B+met_B).Pt()),2)/(pow(lead_B.Pt(),2)+pow(sub_lead_B.Pt(),2)+pow(ph_B.Pt(),2)+pow(met_B.E(),2));
			if((pow(lead_B.Pt(),2)+pow(sub_lead_B.Pt(),2)+pow(ph_B.Pt(),2)+pow(met_B.E(),2))==0)PT_BALANCE_B=1000;
			Hist_pt_B->Fill(PT_BALANCE_B*weight_real_B);
			//if(PT_BALANCE_B>level_pt)
			 if(PT_BALANCE_B<level_pt)	Kr_pt_B=Kr_pt_B+weight_real_B;
			//cutflow_B->Fill(5);
	*/		
	
	}
//вычисление значимостей
/*
	if(Kr_mass_S+Kr_mass_B!=0)Zn_Kr_mass=Kr_mass_S/sqrt(Kr_mass_S+Kr_mass_B);  
	if(Kr_mass_S+Kr_mass_B==0)Zn_Kr_mass=0;
	Hist_zn_mass->Fill(level_mass, Zn_Kr_mass);
		level_mass=level_mass+0.05;
		if(Zn_Kr_mass>max_Zn_Kr_mass) {
			max_Zn_Kr_mass=Zn_Kr_mass;
			max_level_mass=level_mass;
		}
*/	
	
	if(Kr_rapidity_S+Kr_rapidity_B!=0)Zn_Kr_rapidity =Kr_rapidity_S/sqrt(Kr_rapidity_S+Kr_rapidity_B);
	if(Kr_rapidity_S+Kr_rapidity_B==0)Zn_Kr_rapidity =0;
	//cout<<Zn_Kr_rapidity<<endl;
	Hist_zn_rap->Fill(level_rap, Zn_Kr_rapidity);
		level_rap=level_rap-0.01;
		if(Zn_Kr_rapidity>max_Zn_Kr_rap) {
			max_Zn_Kr_rap=Zn_Kr_rapidity;
			max_level_rap=level_rap;
		}
	
/*	
	if((Kr_cetr_S+Kr_cetr_B)!=0) Zn_Kr_cetr =Kr_cetr_S/sqrt(Kr_cetr_S+Kr_cetr_B);    
	if(Kr_cetr_S+Kr_cetr_B==0) Zn_Kr_cetr=0;
	Hist_zn_centr->Fill(level_centr, Zn_Kr_cetr);
		level_centr=level_centr+0.05;
		if(Zn_Kr_cetr>max_Zn_Kr_cetr) {
			max_Zn_Kr_cetr=Zn_Kr_cetr;
			max_level_cetr=level_centr;
		}

*/		
/*		
	if(Kr_pt_S+Kr_pt_B!=0) Zn_Kr_pt =Kr_pt_S/sqrt(Kr_pt_S+Kr_pt_B);  
	if(Kr_pt_S+Kr_pt_B==0) Zn_Kr_pt=0;
	Hist_zn_pt->Fill(level_pt, Zn_Kr_pt );
	level_pt=level_pt+0.05;
	if(Zn_Kr_pt>max_Zn_Kr_pt) {
	max_Zn_Kr_pt=Zn_Kr_pt;
	max_level_pt=level_pt;
	}
*/	
		//
	//cout<<max_Zn_Kr_pt<<"\n"<<Zn_Kr_pt<<"\n"<<"\n";
//	cout<<max_Zn_Kr_cetr<<"\n"<<Zn_Kr_cetr<<"\n"<<"\n";
	//cout<<max_Zn_Kr_mass<<"\n"<<Zn_Kr_mass<<"\n"<<"\n";
	
	cout<<max_Zn_Kr_rap<<"\n"<<level_rap-0.01<<"\n"<<Zn_Kr_rapidity<<"\n"<<"\n";
	Kr_pt_S=0;
	Kr_pt_B=0;
	Kr_cetr_S=0;
	Kr_cetr_B=0;
	Kr_mass_S=0;
	Kr_mass_B=0;
	Kr_rapidity_S=0;
	Kr_rapidity_B=0;
	
	} 

	//std::cout<<"max_Zn_Kr_pt="<< max_Zn_Kr_pt<< std::endl;
	//std::cout<<"level_pt"<< max_level_pt<< std::endl;
	

	f1->Close();
	f2->Close();
	//Double_t scale1= 1/cutflow_S->Integral() ;
	//Double_t scale2= 1/cutflow_B->Integral() ;
	//Double_t scale3= 1/cutflow->Integral() ;
	//Double_t scale4= 1/cutflow1->Integral() ;
	//Double_t scale5= 1/cutfloww->Integral() ;
	//Double_t scale6= 1/cutflow2->Integral() ;
	Double_t scale_pt_bal_S= 1/Hist_pt_S->Integral() ;
	Double_t scale_pt_bal_B= 1/Hist_pt_B->Integral() ;
	
	Double_t scale_mass_S= 1/Hist_mass_S->Integral() ;
	Double_t scale_mass_B= 1/Hist_mass_B->Integral() ;
	
	Double_t scale_rap_S= 1/Hist_rap_S->Integral() ;
	Double_t scale_rap_B= 1/Hist_rap_B->Integral() ;
	
	Double_t scale_centr_S= 1/Hist_centr_S->Integral() ;
	Double_t scale_centr_B= 1/Hist_centr_B->Integral() ;
 
	//cutflow_S->Scale(scale1) ;
	//cutflow_B->Scale(scale2) ;
	//cutflow1->Scale(scale3) ;
	//cutflow2->Scale(scale5) ;
	Hist_pt_S->Scale(scale_pt_bal_S);
	Hist_pt_B->Scale(scale_pt_bal_B);
	
	Hist_mass_S->Scale(scale_mass_S);
	Hist_mass_B->Scale(scale_mass_B);
	
	Hist_rap_S->Scale(scale_rap_S);
	Hist_rap_B->Scale(scale_rap_B);
	
	Hist_centr_S->Scale(scale_centr_S);
	Hist_centr_B->Scale(scale_centr_B);
 
 
	//c->cd(1);
	//cutflow1->Draw("HIST");
	//cutflow2->SetLineColor(6);
	//cutflow2->Draw("HIST same");
  
//	auto legend = new TLegend(0.1,0.7,0.48,0.9);
//	legend->AddEntry(cutflow1,"singnal","l");
//	legend->AddEntry(cutflow2,"background","l");
//	legend->Draw();
//	c->cd(2);
//	cutflow_S->Draw("HIST");
//	cutflow_B->SetLineColor(6);
//	cutflow_B->Draw("HIST same");
	
    b->cd(1);
/*	//b->SetLogy();
	Hist_pt_S->Draw("HIST");	
	Hist_pt_B->SetLineColor(6);
	Hist_pt_B->Draw("HIST same");
*/
/*	
	Hist_mass_S->Draw("HIST");
	Hist_mass_B->SetLineColor(6);
	Hist_mass_B->Draw("HIST same");
*/	
	
	Hist_rap_S->Draw("HIST");
	Hist_rap_B->SetLineColor(6);
	Hist_rap_B->Draw("HIST same");
	
/*	
	Hist_centr_S->Draw("HIST");
	Hist_centr_B->SetLineColor(6);
	Hist_centr_B->Draw("HIST same");
*/
/* 
	auto legend1 = new TLegend(0.6,0.7,0.48,0.9);
	legend1->AddEntry(Hist_pt_S,"singnal","l");
	legend1->AddEntry(Hist_pt_B,"background","l");
	legend1->Draw();
*/	
/*	
	auto legend1 = new TLegend(0.6,0.7,0.48,0.9);
	legend1->AddEntry(Hist_centr_S,"singnal","l");
	legend1->AddEntry(Hist_centr_B,"background","l");
	legend1->Draw();
*/	
/*	
	auto legend1 = new TLegend(0.6,0.7,0.48,0.9);
	legend1->AddEntry(Hist_mass_S,"singnal","l");
	legend1->AddEntry(Hist_mass_B,"background","l");
	legend1->Draw();
*/	
	
	auto legend1 = new TLegend(0.6,0.7,0.48,0.9);
	legend1->AddEntry(Hist_rap_S,"singnal","l");
	legend1->AddEntry(Hist_rap_B,"background","l");
	legend1->Draw();
	
	//b->cd(2);
	//Hist_zet_S->Draw("HIST");
	//Hist_zet_B->SetLineColor(6);
	//Hist_zet_B->Draw("HIST same");
	b->cd(2);
	//значимость pt-balabnce
//	Hist_zn_pt->Draw("HIST");
	
	//значимость centr 
	//Hist_zn_centr->Draw("HIST");
	
	//инвариантная масса 
	//Hist_zn_mass->Draw("HIST");
	
	//разность быстрот 
	Hist_zn_rap->Draw("HIST");
	

  }
