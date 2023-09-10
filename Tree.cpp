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

        Node* getEmpty(){
            int depth=getDepth();
            int index=0;
            if(depth==-1){
                return error;
            }
            Node* current=head;
            while(current!=error){
                current=getNode(depth,index);
                index=index+1;
            }
            index-=1;
            std::cout<<index<<std::endl;
            return getNode(depth,index);
            
        }
        //void display
        //void insert
};
int main(){
    Node head('c');
    Node* headNode=&head;
    Tree tree(&head);
    std::cout<<tree.getDepth()<<std::endl;
    std::cout<<(tree.getEmpty())->data;

}