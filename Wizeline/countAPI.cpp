#include <memory>
class Node{
    public:
    Node(string directory){
        this->directory = directory;
        this->count = 1;
        this->children=vector<unique_ptr<Node>>();
    }
    vector<unique_ptr<Node>> children;
    string directory;
    int count;
};

vector<string> tokenize(string s, string del = " ")
{
    vector<string> tokens;
    int start = 0;
    int end = s.find(del);
    while (end != -1) {
        if(end-start!=0)
            tokens.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    tokens.push_back(s.substr(start, end - start));
    return tokens;
}

void in_order_traversal(Node* node, int level, vector<string>& res)
{
    if(level==0)
    {
        
    }
    else{
        stringstream ss;
        for(int i=0; i<level; i++){
            ss << "--";
        }
        ss<<node->directory;
        ss<<" (";
        ss<<node->count;
        ss<<")";
        res.push_back(ss.str());
        
        
    }
    for(auto& child : node->children){
            in_order_traversal(child.get(), level+1, res);
        }
}

vector<string> solution(vector<string> calls) {
    vector<string> res;
    unique_ptr<Node> root(new Node(""));
    for(auto call : calls)
    {
        // parse call
        Node* currNode = root.get();
        auto tokens = tokenize(call,"/");
        for(auto token : tokens)
        {
            Node* nextNode = nullptr;
            // loop over children, check if child already exists
            for(auto& child : currNode->children)
            {
                if(child->directory==token){
                    nextNode = child.get();
                    break;
                }
            }
            // create new node
            if(nextNode == nullptr)
            {
                auto newNode = unique_ptr<Node>(new Node(token));
                currNode->children.push_back(std::move(newNode));
                nextNode = currNode->children.back().get();
            }
            // increment count
            else{
                nextNode->count+=1;
            }
            currNode=nextNode;
        }
    }
    
    in_order_traversal(root.get(),0, res);
    
    
    return res;
}

