#include<iostream>
using namespace std;

// the second version and because the initial version has unknown problem
// so i have delete all the code and remake this version

// W H Y it still has segment fault ? ? ?


/*
struct Node{
    char s[50];
    Node *next;
};

int main(){
    Node *head = NULL;
    Node *p = new Node;
    p->next = NULL;
    Node *local = p; head = p;
    while(cin >> local->s){
        Node *q = new Node;
        q->next = local;
        head = q;
        local = q;
        q->next = NULL;
    }

    Node *t = head->next;
    for(; t->next != NULL; t = t->next)
        cout << t->s << " ";
    cout << t->s;

    return 0;
}

*/

// to avoid the segment fault i will give up the list!!!
// array is enough!

/*
int main(){
    char s[10000][200];
    int i = 0;
    while(cin >> s[i++]){
        ;
    }
    --i;
    while(i > 1)
        cout << s[--i] << " ";

    cout << s[0];

    return 0;
}
*/

// shit 
// the requirement is use the list and the data part is a char
// so i make the third version

struct Node{
    char s;
    Node *next;
};

int main(){
    char str[1000001];
    cin.getline(str, 1000001);

    Node *head = NULL, *tail = NULL;

    for(int i = 0; str[i]; i++){
        if(str[i] != ' '){
            if(head == NULL){
                Node *p = new Node;
                p->next = NULL;
                p->s = str[i];
                head = p;
                tail = p;
            }
            else{
                Node *p = new Node;
                if(tail->next == NULL)
                    p->next = NULL;
                else
                    p->next = tail->next;
                tail->next = p;
                tail = p;
                p->s = str[i];
            }
        }
        else{
            Node *p = new Node;
            p->s = ' ';
            p->next = head;
            head = p;
            tail = p;
        }
    }

    for(Node *t = head; t != NULL; t = t->next)
        cout << t->s;
    
    return 0;
}