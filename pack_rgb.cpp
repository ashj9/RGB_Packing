#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

template<class Container>
void split_string(const string& in_str, Container& container_, char delim)
{
    std::stringstream ss(in_str);
    std::string token;
    while(std::getline(ss, token, delim))
    {
        container_.push_back(stoi(token));
    }
    
}
vector<double> colour_value_generator() ;

int main(int argc, char ** argv){
        vector<double> colours_vec = colour_value_generator();

        for(int i=0;i<colours_vec.size(); ++i)
        {
                cout<<colours_vec[i]<<endl;
        }
}




vector<double> colour_value_generator() {
   
    ifstream file;
    file.open("./colours.txt");
    if(!file){
        cout<<"Error opening the file"<<endl;
        
    }
    string line;
    vector<vector<size_t> > colour_vectors;
    while(getline(file, line)){
        
        vector<size_t> vec;
        if(line =="")
        {
        break;
        }
        split_string(line, vec, ',');
        colour_vectors.push_back(vec);
    }
    
    vector<double> packed_rgbs;
    for(int i =0; i< colour_vectors.size(); ++i)
    {  
        double packed_rgb = 0;
        packed_rgb = colour_vectors[i][0]<<16 | colour_vectors[i][1] << 8 | colour_vectors[i][2];
      //  packed_rgb = packed_rgb + colour_vectors[i][1] << 8;
        //packed_rgb = packed_rgb + colour_vectors[i][2];
        packed_rgbs.push_back(packed_rgb);
        cout<<packed_rgbs[i]<<endl;
    }
   
    return packed_rgbs;
 }

