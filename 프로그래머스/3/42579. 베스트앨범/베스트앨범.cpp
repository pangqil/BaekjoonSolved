#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool compareGenre(pair<string,int> a,pair<string,int> b){
    return a.second>b.second;
}

bool compareSongs(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}

vector<int> solution(vector<string> genres,vector<int> plays){
    
    vector<int> answer;
    map<string,vector<pair<int,int>>> lis;
    map<string,int> genrerank;
    
    for(int i=0;i<genres.size();i++){
        lis[genres[i]].push_back({plays[i],i});
    }
    
    for(auto it:lis){
        string genrename=it.first;
        for(auto g:it.second){
            genrerank[genrename]+=g.first;
        }
    }
    vector<pair<string,int>> sortedGenres(genrerank.begin(),genrerank.end());
    
    sort(sortedGenres.begin(),sortedGenres.end(),compareGenre);
    
    for(auto it:sortedGenres){
        string genreName=it.first;
        vector<pair<int,int>> songList=lis[genreName];
        sort(songList.begin(),songList.end(),compareSongs);
        int count=0;
        
        for(auto g:songList){
            if(count>=2)break;
            answer.push_back(g.second);
            count++;
        }
    }
    return answer;
}