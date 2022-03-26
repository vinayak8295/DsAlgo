#include<bits/stdc++.h>

using namespace std;
#define ll long long int



class linked_list {
  public:
    ll data;
  linked_list * next;
  linked_list() {
    this -> next = NULL;
  }
  linked_list(ll data) {
    this -> data = data;
    this -> next = NULL;
  }
  linked_list * add(ll data, linked_list * head) {
    // CASE:1
    if (head == NULL) {
      linked_list * temp = new linked_list(data);
      head = temp;
    } else {
      // CASE:2
      linked_list * temp = head;
      while (temp -> next != NULL)
        temp = temp -> next;
      temp -> next = new linked_list(data);
    }
    return head;
  }
};

bool isloop(linked_list* head){
  if(head==NULL)
            return false;
        linked_list *fast = head->next;
        linked_list *slow = head;
        
        
        
        while(fast!=slow){
            
            if(fast==NULL || fast->next==NULL){
                return false;
            } 
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return true;
}
linked_list* remove_loop(linked_list* head){
  auto sp=head,fp=head;
		while(fp and fp->next)
		{
			sp=sp->next;
			fp=fp->next->next;
			if(sp==fp)
				break;
		}
		if(sp==fp)
		{
			sp=head;
			while(sp->next!=fp->next)
			{
				sp=sp->next;
				fp=fp->next;
			}
			fp->next=NULL;
		}
		return head;

}
int main(){
    linked_list* head1 = NULL;
    head1=head1->add(4,head1);
	  head1=head1->add(5,head1);
	  head1=head1->add(7,head1);
    head1=head1->add(8,head1);
    head1->next->next->next->next = head1->next;
    cout<<"LOOP DETECTION"<<endl;
    cout<<isloop(head1)<<endl;
    cout<<"REMOVE LOOP"<<endl;
    linked_list* rl = remove_loop(head1);
    
    return 0;
}