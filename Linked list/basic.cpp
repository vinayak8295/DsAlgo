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

void lprint(linked_list* head1){
    linked_list* mo = head1;
    while (mo)
    {
        cout<<mo->data<<" ";
        mo = mo->next;
    }
    
}

linked_list* rotate(linked_list* head1, int n){
  if(!head1){
            return head1;
        }
  linked_list* counter = head1;
  int size = 0;
  while(counter){
    size++;
    counter = counter->next;

  }
  n = n%size;
  while (n--)
  {
    linked_list* slow;
    linked_list* fast = head1;
    while (fast && fast->next)
    {
           slow = fast;
           fast = fast->next;
    }
    fast->next = head1;
    head1 = fast;
    slow->next = NULL;
    
  }
  return head1;
  
}

linked_list* reverse(linked_list* head1){
    linked_list* cur = head1;
    linked_list* prev = NULL;
    linked_list* nexts = NULL;
    while(cur){
      nexts = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nexts;
    }
    head1 = prev;
    return head1;
}
linked_list* dup_sort(linked_list* head){
     if(!head) return head;
	linked_list* tmp = head;

	while(tmp && tmp -> next)
	{
		if(tmp -> data == tmp -> next -> data)
			tmp -> next = tmp -> next -> next;
		else
			tmp = tmp -> next; 
	}

	return head;
}
linked_list* dup_unsort(linked_list* head){
        map<int,int> mp;
        linked_list* prev=head;
        linked_list* cur=head;
        
        while (cur)
        {
          if(mp[cur->data]){
               prev->next = cur->next;
               cur = cur->next;
               continue;
          }else{
            mp[cur->data]=1;
            prev = cur;
            cur = cur->next;
            continue;
          }
         
        }
        return head;
}

bool palindrome(linked_list* head1){
    stack<int> s;
    linked_list* fast = head1;
    linked_list* slow = head1;
    linked_list* counter = head1;
    int size=0;
    while(counter){
        counter = counter->next;
        size++;
    }
    if(size==1)
    return true;
    while(fast && fast->next){
        s.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(size%2!=0){
        slow = slow->next;
    }
    while (slow)
    {
        int temp;
        temp = s.top();
        s.pop();
        if(temp!=slow->data)
           return false;

        slow = slow->next;
           
    }
    return true;
}

linked_list* merge_sort(linked_list* l1, linked_list* l2){
  linked_list* dummy = new linked_list(-1);
  linked_list* pointer = dummy;
  while (l1 and l2)
  {
    if(l1->data > l2->data){
          pointer->next = l2;
          l2 = l2->next;
    }else{
      pointer->next = l1;
      l1 = l1->next;
    }
    pointer=pointer->next;
  }
  if(l1){
    pointer->next = l1;
    l1=l1->next;
    pointer=pointer->next;
  }
  if(l2){
    pointer->next = l2;
    l2=l2->next;
    pointer=pointer->next;
  }
   
  return dummy->next;
}

linked_list* sort_ll(linked_list* head){

   if(head==NULL or head->next==NULL){
     return head;
   }

   linked_list* slow = head;
   linked_list* fast = head;
   while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
   } 
   linked_list* l2 = slow->next;
   slow->next = NULL;
   linked_list* l1 = head;
   l1 = sort_ll(l1);
   l2 = sort_ll(l2);
   linked_list* sorted = merge_sort(l1,l2);
   return sorted;
}
linked_list* add_ll(linked_list* l1,linked_list* l2){
  int carry=0;
  linked_list* dummy = new linked_list(-1);
  linked_list* cur = dummy;
  while (l1 or l2 or carry)
  {
      if(l1){
        carry+=l1->data;
        l1=l1->next;
      }
      if(l2){
        carry+=l2->data;
        l2=l2->next;
      }
      linked_list* newnode = new linked_list(carry%10);
      cur->next = newnode;
      cur = cur->next;
      carry /=10;
  }
  
  return dummy->next;
} 
int main() {
    linked_list* head1 = NULL;
    head1=head1->add(4,head1);
	  head1=head1->add(5,head1);
	  head1=head1->add(7,head1);
    cout<<"print"<<endl;
    lprint(head1);
    cout<<endl;
    // linked_list* head2 = NULL;
    // head2=head2->add(1,head2);
    // head2=head2->add(3,head2);
    // head2=head2->add(5,head2);
    // cout<<"print"<<endl;
    // lprint(head2);
    // cout<<endl;
    // cout<<"ADD"<<endl;
    // linked_list* addll = add_ll(head1,head2);
    // lprint(addll);
    // cout<<endl;
    // cout<<"palindrome"<<endl;
    // cout<<palindrome(head1)<<endl;
    // cout<<"REVERSE"<<endl;
    // linked_list* reverse_head = reverse(head1);
    // lprint(reverse_head);
    // cout<<endl;
    // cout<<"ROTATE"<<endl;
    // linked_list* rotate_head = rotate(head1,2);
    // lprint(rotate_head);
    // cout<<endl;
    // cout<<"DUPLICATE IN SORTED"<<endl;
    // linked_list* dup = dup_sort(head1);
    // lprint(head1);
    // cout<<endl;
    // cout<<"DUPLICATE IN SORTED"<<endl;
    // linked_list* dup_un = dup_unsort(head1);
    // lprint(dup_un);
    // cout<<endl;
    // cout<<"SORT THE ARRAY"<<endl;
    // linked_list* sort_head = sort_ll(head1);
    // lprint(sort_head);
    // cout<<endl;
    



    
    
    
  return 0;
}