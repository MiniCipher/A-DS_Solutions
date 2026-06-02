class BrowserHistory 
{
    vector<string> vec;
    int size = 0;
    int ind = -1;
public:
    BrowserHistory(string homepage) {
        vec.push_back(homepage);
        size = 1;
        ind = 0;
    }
    
    void visit(string url) 
    {
        if(ind + 1 < vec.size())
            vec[ind + 1] = url;
        else
            vec.push_back(url);
        
        
        ind++;
        size = ind + 1;
    }
    
    string back(int steps) {
        ind = ind - steps;
        ind = max(ind, 0);

        return vec[ind];
    }
    
    string forward(int steps) {
        if(ind + steps < size)
            ind += steps;
        else
            ind = size - 1;
        

        return vec[ind];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
