#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorthim>
#include <cctype>
using namesapce std;

vector<int> bubble(vector<int>& vec){ 
  int n=vec.size();
  for (int i=0;i<n-1;i++){
    bool swap=false;
    for (int j=0;j<n-1;j++){
      int a=vec[j];
      int b=vec[j+1];
      if (a>b){
        swap(vec[j],vec[j+1]);
        swap=true;
      }
    }
    if (swap==false){
        break;}
  }
  return vec;
}

string trim(const string& line){
  const auto first =find_if_not(line.begin,line.end(), [](unsigned char c){return isspace(c);});

  if (first ==line.end()){
    return "";
  }
  const auto last=find_if_not(line.rbegin(),line.rend(),[](unsigned char c){return isspace(c);});

  return string(first,last);
}

int main(){
  string line;
  getline(cin,line);
  string trim_line=trim(line);
  int num;
  try {
    num=stoi(line);
  }catch (const invalid_argument& e){
    cerr<<"Error : Invalid argument for stoi()"<<endl;
  }catch (const out_of_range& e){
    cerr<<"Error : Value is too small for the integer or too large "<<endl;}
  vector<string> inpu(num);
  for (int i=0;i<num;i++){
    cin.ignore();
    string line;
    getline(cin,line);
    inpu.push_back(trim(line));}
  
  for (int j=0;j<num;j++){
    string line=inpu[j];
    int nu;
    vector<int> so;
    stringstream ss(line);
    while (ss>>nu){
      so.push_back(nu);}
    vector<int> sort=bubble(so);
    for (int k=0;k<sort.size();k++){
      cout<<sort[k]<<" ";}
    cout<<endl;}
  return 0;
}
