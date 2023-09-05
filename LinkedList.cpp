#include <iostream>
#include <string>

class Node{
    public:
    char data;
    struct Node* next;
    Node(char elem): data(elem),next(nullptr){};
    
};
class LinkedList{
    public:
        Node* head;
    public:
        LinkedList():head(nullptr){};
        LinkedList(const std::string& inputString) : head(nullptr) {
            for (char elem : inputString) {
                insert(elem);
            }
        }
        void insert(char c){
            Node* newNode=new Node(c);
            if(!head){
                head = newNode;
            }
            else{
                Node* current=head;
                while(current->next){
                    current=current->next;
                }
                current->next=newNode;
            }   
        }

        void display(){
            Node* current=head;
            while(current){
                std::cout << current->data;
                current=current->next;
            }
            std::cout << std::endl;
        }

        ~LinkedList(){
            Node* current=head;
            while(current){
                Node* temp=current;
                current=current->next;
                delete temp;
            }
        }
        void ring(){
            Node* current=head;
            while(current->next){
                current=current->next;
            }
            current->next=head;
        } 
        void swap(Node** n1, Node** n2) {
            Node* temp = *n1;
            *n1 = *n2;
            *n2 = temp;
            temp=(*(*n2)).next;
            (*(*n2)).next=(*(*n1)).next;
            (*(*n1)).next=temp;
        } 
        Node* getHead(){
            return head;
        }
        void sort(){
            Node** node1 = &(head);

        while (*node1 != nullptr) {
            Node** temp = &((*node1)->next);
            Node** minNode=node1;
            while ((*temp) != nullptr) {
                if(((*temp)->data)<((*minNode)->data)){
                    minNode=temp;
                }
                temp=&((*temp)->next);
                }
            if(minNode!=node1){
                swap(minNode,node1);
            }
            node1=&((*node1)->next); 
    }
        }
};

int main() {
    LinkedList list("gfedcba");
    list.sort();
    list.display();
    return 0;
}
        int getMaxIndex(){
            current=head;
            int index=0;
            while(current){
                current=
            }
        }