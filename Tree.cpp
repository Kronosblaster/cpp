#include <iostream>
#include <string>
#include <math.h>

class Node{
    public:
    char data;
    Node* left;
    Node* right;
    Node(char elem): data(elem),left(nullptr),right(nullptr){};
    Node(): data('E'),left(nullptr),right(nullptr){};
    bool nullcheck(){
        if(right==nullptr && left==nullptr){
            return true;
        }
    }
    
};
class Tree{
    public:
        Node* head;
        Node* error;
    public:
        Tree():head(nullptr),error(new Node('X')){};
        Tree(Node* headNode): head(headNode), error(new Node('X')) {};

        Node* getNode(int depth,int index){
            Node* current=head;
            index=(int)pow(2,depth)-index-1;
            if(index<0){
                return error;
            }
            bool switcher=0;
            int temp_depth=0;
            while(depth-temp_depth){
                if(!((int)pow(2,index-temp_depth) )){
                return error;
            }
                switcher=static_cast<bool>(( depth / ((int)pow(2,index-temp_depth) ))%2);
                if(switcher){
                    current=current->right;
                }
                else{
                    current=current->left;
                }
                if(current==nullptr){
                    return error;
                }
                temp_depth+=1;
            }

            return current;
            }
        
        
        int getDepth(){
            if(head==nullptr){
                return -1;
            }
            Node*current=head;
            int depth=0;
            while((current->left)!=nullptr){
                depth+=1;
                current=current->left;
            }
            return depth;
        }

        Node** getEmpty(){
            int depth=getDepth();
            int index=0;
            if(depth==-1){
                return &head;
            }
            Node* current=head;
            while(current!=error){
                current=getNode(depth,index);
                index=index+1;
            }
            index-=1;
            if(index==(int)pow(2,depth)){
                index=0;
                current=getNode(depth,index);
                return &(current->left);
            }

            bool switcher=false;
            if(index%2==0)
                switcher=true;
            else
                switcher=false;
            depth-=1;
            index=index/2;
            
            current=getNode(depth,index);
            if(switcher)
                return &(current->left);
            else
                return &(current->right);
            
        }
        void insert(Node node){
            Node** current=getEmpty();
            *current=&node;
        }
        std::string getData(){
            std::string word;
            Node* current=head;
            int depth=getDepth();
            for(int i=0;i<=depth;i++){
                for(int j=0;j<(int)pow(2,i);j++){
                    current=getNode(i,j);
                    if(current==error){
                        break;
                    }
                    else{
                        word+=current->data;
                    }
                }
            }
            return word;
        }
};
int main(){
    Node head('c');
    Node a('a');
    Node b('b');
    head.left=&a;
    Node* headNode=&head;
    Tree tree(&head);
    tree.insert(b);
    std::cout<<tree.getData();
}