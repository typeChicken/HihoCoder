#include <iostream>
#include <list>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
bool is_mirror_word(string src_word,string tar_word);
bool has_mirror_word(vector<string>* word_vector,string tar_word);
int main()
{
    int word_count;
    int mirror_word_count = 0;
    cin>>word_count;
    vector<string> word_vector;
    for(int i=0;i<word_count;++i)
    {
        string str;
        cin>>str;
        if(has_mirror_word(&word_vector,str))
            ++mirror_word_count;
        else
            word_vector.push_back(str);
    }
    cout<<mirror_word_count;
    return 0;
}
bool has_mirror_word(vector<string>* word_vector,string tar_word)
{
    bool is_has = false;
    for(int i=0;i<word_vector->size();++i)
    {
        if(is_mirror_word(word_vector->at(i),tar_word))
        {
            is_has = true;
            break;
        }
    }
    return is_has;
}
bool is_mirror_word(string src_word,string tar_word)
{
    if(src_word.size() != tar_word.size())
        return false;
    for(int i=0; i<src_word.size();++i)
    {
        if(src_word.at(i) != tar_word.at(tar_word.size()-i-1))
            return false;
    }
    return true;
}


