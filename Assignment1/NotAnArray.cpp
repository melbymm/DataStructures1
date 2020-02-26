#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <cctype>

using namespace std;

int main(int argc, char **argv){
//variables that don't need to be reset every loop
  bool cont = true;
  string filename = "";
  string appFileName = "";
  int loopcount = 0;
//variable declarations
  while(cont){

    string dna = "";
    float length = 0.0;
    ifstream infs;
    float lengthcount = 0.0;
    float stringsCount = 0.0;
    float mean = 0.0;
    float variance = 0.0;
    float stDev = 0.0;
    float devMean = 0.0;
    float meanDiff = 0.0;
    float diffSQ = 0.0;
    float totalSQDiff = 0.0;
    float meanDiffSq = 0.0;
    float ACount = 0.0;
    float CCount = 0.0;
    float GCount = 0.0;
    float TCount = 0.0;
    float AACount = 0.0;
    float ATCount = 0.0;
    float ACCount = 0.0;
    float AGCount = 0.0;
    float CACount = 0.0;
    float CCCount = 0.0;
    float CGCount = 0.0;
    float CTCount = 0.0;
    float GACount = 0.0;
    float GCCount = 0.0;
    float GGCount = 0.0;
    float GTCount = 0.0;
    float TACount = 0.0;
    float TCCount = 0.0;
    float TGCount = 0.0;
    float TTCount = 0.0;
    string NoSpaceStrings = "";
    ofstream ofs;
    string contString = "";
    string allTheStrings = "";

    if(loopcount < 1){
    //make sure you receive a command line argument
      if(argc == 1){
        cerr << " Enter an argument into the command line plz" << endl;
        exit(1);
      }
      else {
        filename = argv[1];

        try{
          infs.open(filename);
      } catch (exception e){
          cout << "Could not open the file. " << endl;
          break;
      }
          }
      }
      else{

        try{
          infs.open(appFileName, std::ios_base::app);
      } catch (exception e){
          cout << "Could not open the file. " << endl;
          break;
      }

      }

//only continue if file is open
    if(infs.is_open()){

      while(!infs.eof()){
        infs >> dna;
        allTheStrings = allTheStrings + dna + " ";
        //sets lower case letters to uppercase
        for (int i = 0; i < allTheStrings.length(); ++i){
          if(islower(allTheStrings.at(i))){
            allTheStrings.at(i) = toupper(allTheStrings.at(i));
          }
        }

        NoSpaceStrings += dna;
        for (int i = 0; i < NoSpaceStrings.length(); ++i){
          //sets lowercase letters to upper
          if(islower(NoSpaceStrings.at(i))){
            NoSpaceStrings.at(i) = toupper(NoSpaceStrings.at(i));
          }
        }
        stringsCount = stringsCount + 1;

        for (int i = 0; i < dna.length(); ++i){
          ++lengthcount;
        }

        mean = lengthcount / stringsCount;
  }
        std :: stringstream streamer;
        streamer << allTheStrings;
        //cout << "String length: " << allTheStrings.length() << endl;
        string temp = "";
        //streamer allows for calculating one string at a time
        while(streamer >> temp){
          meanDiff = temp.length() - mean;
          diffSQ = pow(meanDiff,2);
          totalSQDiff += diffSQ;
          meanDiffSq = totalSQDiff / stringsCount;
        }
//check count for letters
        for (int k = 0; k < NoSpaceStrings.length(); ++k){
          if(NoSpaceStrings.at(k) == 'A'){
//iterate for A count
            ACount += 1;
            if(k % 2 == 0){
              //cout << "It's the first half! " << endl
              //check count for bigrams
              if(NoSpaceStrings.at(k+1) == 'A'){
                AACount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'C'){
                ACCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'G'){
                AGCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'T'){
                ATCount += 1;
              }
            }

          }
//iterate for C count
          else if(NoSpaceStrings.at(k) == 'C'){
            CCount += 1;

            if(k % 2 == 0){
              if(NoSpaceStrings.at(k+1) == 'A'){
                CACount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'C'){
                CCCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'G'){
                CGCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'T'){
                CTCount += 1;
              }
            }
          }
          //iterate for G count

          else if(NoSpaceStrings.at(k) == 'G'){
            GCount += 1;
        //    cout << "G Count: " << GCount << endl;
            if(k % 2 == 0){
              if(NoSpaceStrings.at(k+1) == 'A'){
                GACount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'C'){
                GCCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'G'){
                GGCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'T'){
                GTCount += 1;
              }
            }
          }
          //iterate for T count

          else if(NoSpaceStrings.at(k) == 'T'){
            TCount += 1;

            if(k % 2 == 0){
              if(NoSpaceStrings.at(k+1) == 'A'){
                TACount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'C'){
                TCCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'G'){
                TGCount += 1;
              }
              else if(NoSpaceStrings.at(k+1) == 'T'){
                TTCount += 1;
              }
            }
          }


        }


    }
    //makes sure file actually has contents
    if(NoSpaceStrings.size() == 0){
      cout << "File has no contents. " << endl;
      break;
    }


        infs.close();
        //open for appending if second loop or later
        if(loopcount < 1){
          try{
          ofs.open("MitchMelby.out");
        } catch (exception e){
            cout << "Could not open the file. " << endl;
        }

        }
        else{
          try{
            ofs.open("MitchMelby.out", std::ios_base::app);
        } catch (exception e){
            cout << "Could not open the file. " << endl;
        }

        }
//calc standard deviation
        stDev = sqrt(meanDiffSq);
      //calculate variance
        variance = pow(stDev,2);
        ofs << "Mitchell Melby" << endl;
        ofs << "2327121" << endl;
        ofs << "CPSC 350-02" << endl;
        ofs << "Total string length: " << lengthcount << endl;
        ofs << "String count: " << stringsCount << endl;

        ofs << "Mean: " << mean << endl;
        ofs << "Standard Deviation is: " << stDev << endl;
        cout << stDev << endl;
        ofs << "Variance is: " << variance << endl;
        dna = "";
        float Aprob = ACount/NoSpaceStrings.length();
        ofs << "A probability: " << Aprob << endl;

        float Cprob = CCount/NoSpaceStrings.length();
        ofs << "C probability: " << Cprob << endl;
        float Gprob = GCount/NoSpaceStrings.length();
        ofs << "G probability: " << Gprob << endl;
        float Tprob = TCount/NoSpaceStrings.length();
        ofs << "T probability: " << TCount/NoSpaceStrings.length() << endl;

        ofs << "AA probability: " << AACount/(NoSpaceStrings.length()/2) << endl;
        ofs << "AG probability: " << AGCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "AC probability: " << ACCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "AT probability: " << ATCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "GA probability: " << GACount/(NoSpaceStrings.length()/2) << endl;
        ofs << "GC probability: " << GCCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "GG probability: " << GGCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "GT probability: " << GTCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "CA probability: " << CACount/(NoSpaceStrings.length()/2) << endl;
        ofs << "CC probability: " << CCCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "CG probability: " << CGCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "CT probability: " << CTCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "TT probability: " << TTCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "TA probability: " << TACount/(NoSpaceStrings.length()/2) << endl;
        ofs << "TC probability: " << TCCount/(NoSpaceStrings.length()/2) << endl;
        ofs << "TG probability: " << TGCount/(NoSpaceStrings.length()/2) << endl;
        cout << "A: " << ACount << endl;
        cout << "C: " << CCount << endl;
        cout << "G: " << GCount << endl;
        cout << "T: " << TCount << endl;



        for (int i = 0; i < 1000; ++i){
          string oneK = "";
//generate random float
          float a = (float) rand() /(RAND_MAX);


          float b = (float) rand() /(RAND_MAX);
//gaussian distribution
          float varC = sqrt((-2) * log(a)) * cos(2 * M_PI * b );

          float varD = (stDev * varC) + mean;
//make sure lengths are positive
          if(varD < 0){
            varD = varD * -1;
          }
          //outputs strings the length of d
          for(int i = 0; i < varD; ++i ){

            float randNum = (float) rand()/(RAND_MAX);

//chooses which letter to output based on probability from input file
            if(randNum < Aprob){
              oneK += 'A';
            }
            else if(randNum < (Aprob + Cprob)){
              oneK += 'C';
            }
            else if(randNum < (Gprob + Aprob + Cprob)){
              oneK += 'G';
            }
            else {
              oneK += 'T';
            }
          }
          oneK += " ";


          ofs << oneK << endl;

    }
    ofs.close();
    cout << "Would you like to process another file?(Yes/No): " << endl;
    cin >> contString;
    //makes lowers to uppercase
    for(int i = 0; i < contString.length(); ++i){
      contString.at(i) = toupper(contString.at(i));

    }
//gets file name
    if(contString == "YES"){
      cout << "What is the name of the file?: " << endl;
      cin >> appFileName;
      loopcount+=1;
    }
    else{
      cont = false;
      break;
    }

}

}
