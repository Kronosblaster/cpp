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
        Tree():head(nullptr),error(nullptr){};
        Tree(Node* headNode): head(headNode), error(new Node('X')) {};

        Node* getNode(int depth,int index){
            Node* current=head;
            index=(int)pow(2,depth)-index-1;
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
            Node*current=head;
            int depth=0;
            while((current->left)!=nullptr){
                depth+=1;
                current=current->left;
            }
            return depth;
        }

        void insert(Node* node){
            int index=getEmpty();
            int depth=getDepth();
            Node* current=getNode(depth-1,index/2);
            index=index%2;
            if(index){
                current->left=node;
            }                       
            else{
                current->right=node;
            }     
        }
        int getEmpty(){
            int depth=getDepth();
            int index=0;
            Node* current=head;
            while(current!=error){
                current=getNode(depth,index);
                index+=1;
            }
            return index;
            
        }
        void display(){
            int finalIndex=getEmpty();
            int depth=getDepth();
            int i;
            for(int j=0;j<=depth;j++){
  
            if(j!=depth){
                i=0;
                while(i<(int)pow(2,j)){
                    std::cout<<getNode(j,i)->data;
                    i+=1;
                }
            }
            else{
                i=0;
                while(i<finalIndex-1){
                    std::cout<<getNode(j,i)->data;
                    i+=1;
                }
            }
            std::cout<<std::endl;
            }
        }
};
int main(){
    Node head('c');
    Node* headNode=&head;
    Tree tree(headNode);
    //tree.insert((new Node('a')));
    std::cout<<tree.getDepth();
    //tree.display();

}