#include<numeric>
#include<fstream>
#include<vector>
#include<algorithm>



int currDepth(1);                                                                                                   
int numOfNodes(0);
std::vector<std::vector<int>> matrix;
std::vector<int> visitedArr;
 
void DepthFirstSearch(int node)
{
  
    visitedArr[node]=currDepth;
    ++currDepth;
    for(int i(0);i<numOfNodes;++i)
    {
        if(matrix[node][i] && !visitedArr[i])
           DepthFirstSearch(i); 
    }
  
}

int main()
{
    std::ifstream in("input.txt"); 
    std::ofstream out("output.txt"); 

    int sum(0);

    in>>numOfNodes;
    
    matrix.resize(numOfNodes,std::vector<int>(numOfNodes,0));
    visitedArr.resize(numOfNodes,0);
    
    for(int i(0);i<numOfNodes;++i)
        for(int j(0);j<numOfNodes;++j)
            in>>matrix[i][j];
                
    for(auto i: matrix)
        sum+=accumulate(i.begin(),i.end(),0);

    
    if(sum/2 != numOfNodes-1)
    {
        out<<"No";
        in.close();
        out.close();
        return 0;
    }
    
    DepthFirstSearch(0);
    
    if(std::find(visitedArr.begin(),visitedArr.end(),0) !=visitedArr.end())
    {
        out<<"No";    
        in.close();
        out.close();
        return 0;
    }
        
    out<<"Yes";

    in.close();
    out.close();
}
