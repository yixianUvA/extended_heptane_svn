/* ---------------------------------------------------------------------

Copyright IRISA, 2003-2017

This file is part of Heptane, a tool for Worst-Case Execution Time (WCET)
estimation.
APP deposit IDDN.FR.001.510039.000.S.P.2003.000.10600

Heptane is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Heptane is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details (COPYING.txt).

See CREDITS.txt for credits of authorship

------------------------------------------------------------------------ */

/* -----------------------------------------------------
   Main file to call the different steps of WCET estimation
   -------------------------------------------------------- */

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <assert.h>
#include <sys/time.h>

#include "Logger.h"
#include "Generic/Config.h"
#include "Generic/Analysis.h"
#include "SharedAttributes/SharedAttributes.h"
#include "Specific/CacheAnalysis/ICacheAnalysis.h"
#include "Specific/CacheAnalysis/CacheStatistics.h"
#include "Specific/CacheAnalysis/DCacheAnalysis.h"
#include "Specific/SimplePrint/SimplePrint.h"
#include "Specific/DotPrint/DotPrint.h"
#include "Specific/IPETAnalysis/IPETAnalysis.h"
#include "Specific/DataAddressAnalysis/AddressAnalysis.h"
#include "Specific/HtmlPrint/HtmlPrint.h"
#include "Specific/PipelineAnalysis/PipelineAnalysis.h"
#include "Generic/Timer.h"



/**
   Fill configuration object by program then calls WCETcomputation().
   >>>>> Currently not executed.
 */
static void Analysis_by_program()
{
  return; 

 
}


/*! 
 * Entry point of the WCET analyser 
 * Here, automatic execution of analyses from a configuration file
 */

int
main (int argc, char **argv)
{
  string configFile;
  bool printTime = true;
  cout <<  "The argc is " << argc  << endl;
  

  if (argc == 3)
    {
      if ( string(argv[1]) == "-t")
	{
	  Logger::setOptionTrace(false); 
	  printTime = false;
	}
      else
	cout << "Now we start the cache Interference analysis " << argv[1] << "........ " << endl;
    }
  else
    if (argc == 4)
      {
	       cout << "The second program is " << argv[3] << endl;

      }


  if(string (argv[argc-1]) == "./configWCET.xml"){
    configFile = string (argv[argc-1]);
  }
    
  else 
    configFile = string (argv[argc-2]);
  cout << "The First Parameter is " << string(argv[0]) << endl;
  cout << "The configFile is " << configFile << endl;

  //cout << "The successive param is " << string(argv[argc]) << endl;

  
  // Initialisation code (do not remove, useful to create serialisation code
  // for attribute types not supported by cfglib
  AttributesFactory *af = AttributesFactory::GetInstance();
  //AddressAttribute *addressTest = new AddressAttribute();
  af->SetAttributeType (AddressAttributeName, new AddressAttribute ());
  af->SetAttributeType (SymbolTableAttributeName, new SymbolTableAttribute ());
  af->SetAttributeType (ARMWordsAttributeName, new ARMWordsAttribute ());
  af->SetAttributeType (StackInfoAttributeName, new StackInfoAttribute ());
  af->SetAttributeType (CodeLineAttributeName, new CodeLineAttribute ());
  af->SetAttributeType (ContextListAttributeName, new ContextList ());
  af->SetAttributeType (ContextTreeAttributeName, new ContextTree ());
  af->SetAttributeType (MetaInstructionAttributeName, new MetaInstructionAttribute ());
  
  

  Timer timer_AllAnalysis;
  float time = 0.0;
  timer_AllAnalysis.initTimer();


  // Main analysis code from configuration file
  // -------------------------------------------
  Logger::printVersion();
  Logger::printDebug ("Reading configuration file");
  config->FillArchitectureFromXml (configFile);
  Logger::printDebug ("Executing from configuration file");
  config->ExecuteFromXml (configFile, printTime);
  // Instruction Cache interference
  if(string (argv[argc-1]) != "./configWCET.xml"){
    string interferedfile = string (argv[argc-1]);
    string tmpICacheHB = "./resICacheL2.xml";
    // Modify to your path
    for(int i = 0;i < argc;i++)
      cout << "The file name is " << string(argv[i]) << endl;
    string fixpath = "/home/yixian/heptane_svn/benchmarks/";
    vector<Config::HB> hb = config->GenerateIcacheHB(tmpICacheHB);
    cout << hb.size() << endl;
    for(unsigned int i = 0;i < hb.size();i++){
      cout << "Address: "<< dec << hb[i].address << " ,CacheSet: " << hb[i].cacheset << " ,CHMCValue: " << hb[i].CHMCValue << endl;
   }
    string tmpICacheCB = fixpath + interferedfile + "/resICacheL2.xml";
    vector<Config::CB> cb = config->GenerateIcacheCB(tmpICacheCB);
    for(unsigned int i = 0;i < cb.size();i++){
      cout << "CacheSet: " << dec << cb[i].cacheset << " Address: " << cb[i].address << " CACValue: " << cb[i].CACvalue << endl;
    }
    
    string analysislog = "./analysis_ARM_lp_solve.log";
    ifstream file;
    string line;
    map<int,int> fullset;
    vector<int> tmpset;
    file.open(analysislog);
    if(file.is_open()){
        while(getline(file,line)){
            string begin = line.substr(0,4);
            if(begin == "FULL"){
              int pos = line.find(4,' ');
              string cacheset = line.substr(5,pos - 5);
              int nset = stoi(cacheset);
              tmpset.push_back(nset);
            }
            else continue;
        }
    }
    else cout << "The file is unable to open " << endl;
    file.close();
    for(unsigned int i = 0;i < tmpset.size();i++){
      fullset[tmpset[i]]++;
    }
    for(auto i : fullset) cout << "The cache set number is " << i.first << " the sum is " << i.second << endl;
    int sum = 0;
    int hnum = 0,cnum = 0;
    for(auto i : fullset){
      for(unsigned j = 0; j < hb.size();j++){
          if(hb[j].cacheset == i.first) hnum++;
      }
      for(unsigned k = 0; k < cb.size();k++){
        if(cb[k].cacheset == i.first) cnum++;
      }
      sum += i.second * (hnum < cnum ? hnum : cnum);
    }
  
   
    


    map<int,int> conflictIcache;
    map<int,int> conflictDcache;
    map<int,int> conflictUcache;
    int nb_ways = 4;

  
   // This is version about un-united cache
    // Ncb + Nhb > Nways
    map<int,int> hbset;
    map<int,int> cbset;
    int sumI = 0;
    for(unsigned int i = 0;i < hb.size();i++) hbset[hb[i].cacheset]++;
    for(unsigned int i = 0;i < cb.size();i++) cbset[cb[i].cacheset]++;
    int countInter = 0;
    pair<int,int> pairI;
    for(auto i : hbset){
        for(auto j : cbset){
          if(i.first == j.first && i.second + j.second > nb_ways){
            pairI.first = i.first;
            pairI.second = (i.second < j.second ? i.second : j.second);
            conflictIcache.insert(pairI);
            countInter++;
            sumI += (i.second < j.second ? i.second : j.second);
          }
        }
    }
    
    
    //cout << "The number of cache interference is " << sum << endl;
  
  Timer cacheInfertime;
  float Infertime = 0.0;
  cacheInfertime.initTimer();

  // data cache interference analysis
  string tmpDCacheHB = "./resDCacheL2.xml";
    // Modify to your path
  vector<Config::HB> hbdata = config->GenerateIcacheHB(tmpDCacheHB);
  cout << hbdata.size() << endl;
  //for(unsigned int i = 0;i < hbdata.size();i++){
  //  cout << "Address: "<< dec << hbdata[i].address << " ,CacheSet: " << hbdata[i].cacheset << " ,CHMCValue: " << hbdata[i].CHMCValue << endl;
  // }
  string tmpDCacheCB = fixpath + interferedfile + "/resDCacheL2.xml";
  vector<Config::CB> cbdata = config->GenerateIcacheCB(tmpDCacheCB);
  //for(unsigned int i = 0;i < cbdata.size();i++){
  //  cout << "CacheSet: " << dec << cbdata[i].cacheset << " Address: " << cbdata[i].address << " CACValue: " << cbdata[i].CACvalue << endl;
  //}

  
  

  // This version is about united cache
  map<int,int> HBU;
  map<int,int> CBU;
  int sumU = 0;
  for(unsigned int i = 0;i < hb.size();i++) HBU[hb[i].cacheset]++;
  for(unsigned int i = 0;i < cb.size();i++) CBU[cb[i].cacheset]++;
  for(unsigned int i = 0;i < hbdata.size();i++) HBU[hbdata[i].cacheset]++;
  for(unsigned int i = 0;i < cbdata.size();i++) CBU[cbdata[i].cacheset]++;
  pair<int,int> pairU;
  for(auto i : HBU){
        for(auto j : CBU){
          if(i.first == j.first && i.second + j.second > nb_ways){
            sumU += (i.second < j.second ? i.second : j.second);
            pairU.first = i.first;
            pairU.second = (i.second < j.second ? i.second : j.second);
            conflictUcache.insert(pairU);
          }
        }
    }
  cacheInfertime.addTimer(Infertime);
  stringstream infostr1;
  infostr1 << " =======**> Infertime Time = "  << Infertime;
  Logger::addInfo(infostr1.str());
  Logger::print();
  ofstream infertimeprint;
  string tmp = to_string(Infertime);
  infertimeprint.open("/home/yixian/heptane_svn/infertimeprint.txt",ios::app);
  infertimeprint << tmp << endl;
  infertimeprint.close();
    cout << "---------------------------------------------------" << endl;
    cout << "CB and HB size information" << endl;
    cout << "The HB size is " << hb.size() << endl;
    cout << "The CB size is " << cb.size() << endl;
 


 // data Ncb + Nhb > Nways
    map<int,int> hbdataset;
    map<int,int> cbdataset;
    int sumD = 0;
    for(unsigned int i = 0;i < hbdata.size();i++) hbdataset[hbdata[i].cacheset]++;
    for(unsigned int i = 0;i < cbdata.size();i++) cbdataset[cbdata[i].cacheset]++;
    int countInter1 = 0;
    pair<int,int> pairD;
    for(auto i : hbdataset){
        for(auto j : cbdataset){
          if(i.first == j.first && i.second + j.second > nb_ways){
            sumD += (i.second < j.second ? i.second : j.second);
            countInter1++;
            pairD.first = i.first;
            pairD.second = (i.second < j.second ? i.second : j.second);
            conflictDcache.insert(pairD);
          }
        }
    }
 


    
    
    cout << "******The conflict cache set of Instruction cache Interference*****" << endl;
    for(auto i : conflictIcache){
      cout << "Conflict Set: " << i.first << " Evited Items: " << i.second << endl;
    }
    cout << endl;
    cout << "******The conflict cache set of Data cache Interference*****" << endl;
    for(auto i : conflictDcache){
      cout << "Conflict Set: " << i.first << " Evited Items: " << i.second << endl;
    }

    cout << endl;
    cout << "*******************Un-united Cache********************" << endl;
    cout << "The sum of conflict cacheset is " << countInter << endl;
    cout << "The instruction interference is " << sumI << endl;
    cout << "The sum of conflict cacheset is " << countInter1 << endl;
    cout << "The Data Cache Interference is " << sumD << endl;
    cout << "Interfered by program " << interferedfile 
    << " , The times of the evicted item is " << sumI + sumD << endl;
    cout << endl;
    
 

    

  
   


  cout << "\n" << endl;
  cout << "*************This is the version of United cache Interference *************" << endl;
  cout << "Interfered by program " << interferedfile 
    << " , The times of the evicted item is " << sumU << endl;
  cout << "******The conflict cache set of Data cache Interference*****" << endl;
  cout << "The conflictUcache size is " << conflictUcache.size() << endl;

    for(auto i : conflictUcache){
      cout << "Conflict Set: " << i.first << " Evited Items: " << i.second << endl;
    }
  cout << "\n" << endl;

   ofstream outEvitedItems; 	
   outEvitedItems.open("/home/yixian/heptane_svn/L2_128.txt",ios::app);
   string IcacheItem, DcacheItem, UcacheItem;
   IcacheItem = to_string(sumI);
   DcacheItem = to_string(sumD);
   UcacheItem = to_string(sumU);
   string outEvitedString = IcacheItem + "\t" + DcacheItem + "\t" + to_string(sumI + sumD) +"\t" + UcacheItem; 
   outEvitedItems << outEvitedString << endl;
   outEvitedItems.close();

   
  ofstream CAC_CHMC_Information;
  CAC_CHMC_Information.open("/home/yixian/heptane_svn/CAC_CHMC_Information.txt",ios::app);
  Config::CacheInfo cInfo = config->CacheInfoStasticstic(tmpICacheHB);
  CAC_CHMC_Information << "Instruction cache state" << endl;
  CAC_CHMC_Information << "A " << "\t" << cInfo.numberofCACAttrL1A << "\t"; 
  CAC_CHMC_Information << "U " << "\t" << cInfo.numberofCACAttrL1U << "\t";
  CAC_CHMC_Information << "UN " << "\t" << cInfo.numberofCACAttrL1UN << "\t";
  CAC_CHMC_Information << "N " << "\t" << cInfo.numberofCACAttrL1N << "\t";
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information << "AH " << "\t" << cInfo.numberofCHMCL1AH << "\t";
  CAC_CHMC_Information << "FM " << "\t" << cInfo.numberofCHMCL1FM << "\t";
  CAC_CHMC_Information << "NC " << "\t" << cInfo.numberofCHMCL1NC << "\t";
  CAC_CHMC_Information << "AM " << "\t" << cInfo.numberofCHMCL1AM << "\t";
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information << "A " << "\t" << cInfo.numberofCACAttrL2A << "\t"; 
  CAC_CHMC_Information << "U " << "\t" << cInfo.numberofCACAttrL2U << "\t";
  CAC_CHMC_Information << "UN " << "\t" << cInfo.numberofCACAttrL2UN << "\t";
  CAC_CHMC_Information << "N " << "\t" << cInfo.numberofCACAttrL2N << "\t";
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information << "AH " << "\t" << cInfo.numberofCHMCL2AH << "\t";
  CAC_CHMC_Information << "FM " << "\t" << cInfo.numberofCHMCL2FM << "\t";
  CAC_CHMC_Information << "NC " << "\t" << cInfo.numberofCHMCL2NC << "\t";
  CAC_CHMC_Information << "AM " << "\t" << cInfo.numberofCHMCL2AM << "\t";
  CAC_CHMC_Information << endl;

  Config::CacheInfo cInfoD = config->CacheInfoStasticstic(tmpDCacheHB);
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information << "Data cache state" << endl;
  CAC_CHMC_Information << "A " << "\t" << cInfoD.numberofCACAttrL1A << "\t"; 
  CAC_CHMC_Information << "U " << "\t" << cInfoD.numberofCACAttrL1U << "\t";
  CAC_CHMC_Information << "UN "<< "\t" << cInfoD.numberofCACAttrL1UN << "\t";
  CAC_CHMC_Information << "N " << "\t" << cInfoD.numberofCACAttrL1N << "\t";
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information << "AH " << "\t" << cInfoD.numberofCHMCL1AH << "\t";
  CAC_CHMC_Information << "FM " << "\t" << cInfoD.numberofCHMCL1FM << "\t";
  CAC_CHMC_Information << "NC " << "\t" << cInfoD.numberofCHMCL1NC << "\t";
  CAC_CHMC_Information << "AM " << "\t" << cInfoD.numberofCHMCL1AM << "\t";
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information << "A " << "\t" << cInfoD.numberofCACAttrL2A << "\t"; 
  CAC_CHMC_Information << "U " << "\t" << cInfoD.numberofCACAttrL2U << "\t"; 
  CAC_CHMC_Information << "UN "<< "\t" << cInfoD.numberofCACAttrL2UN << "\t";
  CAC_CHMC_Information << "N " << "\t" << cInfoD.numberofCACAttrL2N << "\t";
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information << "AH " << "\t" << cInfoD.numberofCHMCL2AH << "\t";
  CAC_CHMC_Information << "FM " << "\t" << cInfoD.numberofCHMCL2FM << "\t";
  CAC_CHMC_Information << "NC " << "\t" << cInfoD.numberofCHMCL2NC << "\t";
  CAC_CHMC_Information << "AM " << "\t" << cInfoD.numberofCHMCL2AM << "\t";
  CAC_CHMC_Information << endl;
  CAC_CHMC_Information.close();


 

  
// Ncb + Nhb > Nways - Ncontains
   /*
   file.open(analysislog);
    if(file.is_open()){
        while(getline(file,line)){
            string begin = line.substr(0,4);
            if(begin == "FULL"){
              int pos = line.find(4,' ');
              string cacheset = line.substr(5,pos - 5);
              int nset = stoi(cacheset);
              tmpset.push_back(nset);
            }
            else continue;
        }
    }
    else cout << "The file is unable to open " << endl;
    
    file.close();
    */
    

  








    
  }
  
  // Analysis code by program (to be modified for specific purposes)
  Analysis_by_program();

  printTime = false;
  if (printTime)
    {
      timer_AllAnalysis.addTimer(time);
      stringstream infostr;
      infostr << " =======**> Total Time = "  << time;
      Logger::addInfo(infostr.str());
      Logger::print();
    }

  // Cleanup code
  Logger::kill ();
  delete config;

 
  return 0;
}
