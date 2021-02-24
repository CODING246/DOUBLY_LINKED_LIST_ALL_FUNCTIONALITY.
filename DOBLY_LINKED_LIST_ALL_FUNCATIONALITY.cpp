    //DOBLY LINKED LIST ALL FUNCTIONALITY//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 struct Node
 {
     int info;
     struct Node* next;
     struct Node* prev;
 };
 struct Node* head=NULL;
  void insert_element_first_position()
  {
     struct Node* temp;
     temp=(struct Node*)malloc(sizeof(struct Node));
     cout<<"enter a element :"<<endl;
     cin>>temp->info;
     temp->prev=NULL;
     temp->next=NULL;
     if(head==NULL){
         head=temp;
     }else{
   head->prev=temp;
   temp->next=head;
   head=temp;
     }
  }
  void Delete_element_first_position()
  {
  struct Node*t;
  t=head;
  if(head==NULL)
  {
      cout<<"list is empty"<<endl;
  }else{
       head=t->next;
       head->prev=NULL;
       free(t);
     }
  }
  void view_all_element(){
  struct Node* v;
  v=head;
  if(head==NULL)
  {
      cout<<"list is empty"<<endl;
  }else{
    cout<<"list is :"<<endl;
  while(v->next!=NULL)
  {
      cout<<" "<<v->info;
      v=v->next;
  }
  }
  }
  void insert_element_at_end_of_the_list()
  {
      struct Node* p,*temp;
       temp =(struct Node*)malloc(sizeof(struct Node));
      cout<<"enter a number :";
      cin>>temp->info;
      p=head;
      if(head==NULL)
      {
          cout<<"sorry i cant insert in this list"<<endl;
          cout<<"NOTE:-you need to create first list then you can insert"<<endl;
      }else{
        while(p->next!=NULL)
        {
            p=p->next;
        }
        temp->next=NULL;
        p->next=temp;
        temp->prev=p;
      }
  }
  void insert_between_the_Node()
  {
      int n,pos=0;
      struct Node* t,*temp;
      temp =(struct Node*)malloc(sizeof(struct Node));
      cout<<"enter the position the for insert node"<<endl;
      cin>>n;
      cout<<"enter the element :"<<endl;
      cin>>temp->info;
      t=head;
      if(head==NULL)
      {
        cout<<"list is empty"<<endl;
      }else{
        while(t->next!=NULL){
                pos=pos+1;
                t=t->next;
            if(n==pos)
            {
                temp->prev=t;
                 temp->next=t->next;
                temp->next->prev=temp;
                t->next=temp;
            }
        }
      }
  }
     void delete_between_the_node()
     {
         int n=0,pos=0;
         struct Node* temp;
         temp=head;
         if(temp==NULL){
            cout<<"list is empty"<<endl;
         }else{
         cout<<"Enter the position of node"<<endl;
         cin>>n;
         while(temp->next!=NULL){
            pos=pos+1;
            if(n==pos){
              temp->prev->next=temp->next;
              temp->next->prev=temp->prev;
              free(temp);
              cout<<"node is deleted"<<endl;
            }
            temp=temp->next;
         }
     }
     }
     void delete_last_node()
     {
         struct Node* temp;
         temp=head;
         if(temp==NULL){
            cout<<"list is empty"<<endl;
         }else{
            while(temp->next!=NULL){
               temp=temp->next;
            }
             temp->prev->next=NULL;
                free(temp);
         }
     }
     void reverse_linked_list()
     {
        struct Node*p1,*p2;
        p1=head;
        p2=p1->next;
        p1->next=NULL;
        p1->prev=p2;
        while(p2!=NULL)
        {
            p2->prev=p2->next;
            p2->next=p1;
            p1=p2;
            p2=p2->prev;
        }
        head=p1;
        cout<<"list is reversed!"<<endl;
    }
    void sorting_linked_list()
    {
        struct Node* p,*q;
        int temp;
        p=head;
        if(p==NULL){
            cout<<"list is empty"<<endl;
        }
        else
            {
        q=p->next;
        for(p=head;p->next!=NULL;p=p->next){
                for(q=p->next;q->next!=NULL;q=q->next){
            if(p->info>q->info){
                temp=p->info;
                p->info=q->info;
                q->info=temp;
            }
                }
        }
    }
    }
    void sorting_by_bouble_sort()
    {
       //check the neighboring elements ans swap them accordingly.
       //transfer a element at a time to the partially sorted array;
       struct Node* p,*q,*end1;
       int temp;
       p=head;
       if(p==NULL)
       {
           cout<<"list is empty "<<endl;
       }
       else
        {
           for(end1=NULL;end1!=head->next;end1=q)
           {
               for(p=head;p->next!=end1;p=p->next)
               {
                   q=p->next;
                   if(p->info > q->info)
                   {
                       temp=p->info;
                       p->info=q->info;
                       q->info=temp;
                   }
               }
           }
        }

    }
    void rearraning_element_by_selection_sort()
    {
      struct Node* p,*q,*temp,*r,*s;
      for(r=p=head;p->next!=NULL;r=p,p=p->next)
      {
          for(s=q=p->next;q!=NULL;s=q,q=q->next)
          {
              if(p->info>q->info)
              {
                  temp=p->next;
                  p->next=q->next;
                  q->next=temp;
                  if(p!=head)
                    r->next=q;
                  s->next=p;
                  if(p==head)
                    head=q;
                  temp=p;
                  p=q;
                  q=temp;
              }
          }
      }

    }

    int menu()
    {
        int choice;
    cout<<"1.insert element first position"<<endl;
    cout<<"2.delete element first position"<<endl;
    cout<<"3.view all element[traversing]"<<endl;
    cout<<"4.insert element end of the list"<<endl;
    cout<<"5.insert  between the nodes"<<endl;
    cout<<"6.delete between the node[if you want to delete first and last node\n then this function is not work]"<<endl;
    cout<<"7.delete the last node"<<endl;
    cout<<"8.reversed all list"<<endl;
    cout<<"9.sorting all element[SELECTION SORT]"<<endl;
    cout<<"10.sorting all element by[BOUBLE SORT]"<<endl;
    cout<<"11.selection sort by rearranging element"<<endl<<endl<<endl;
    cout<<"Enter your choice :";
    cin>>choice;
    return(choice);
    }
int main()
{
    char ans;
    do{
       system("cls");
    switch(menu())
    {
    case 1:
        {
            insert_element_first_position();
            break;
        }
    case 2:
        {
            Delete_element_first_position();
            break;
        }
    case 3:
        {
            view_all_element();
            break;
        }
    case 4:
        {
            insert_element_at_end_of_the_list();
            break;
        }
    case 5:
        {
            insert_between_the_Node();
            break;
        }
    case 6:
        {
          delete_between_the_node();
          break;
        }
    case 7:
        {
          delete_last_node();
          break;
        }
    case 8:
        {
            reverse_linked_list();
            break;
        }
    case 9:
        {
            sorting_linked_list();
            break;
        }
    case 10:
        {
          sorting_by_bouble_sort();
          break;
        }
    case 11:
        {
            rearraning_element_by_selection_sort();
            break;
        }
    }
    cout<<endl<<"Do you want to continue(y/n):";
    cin>>ans;
    }while(ans=='y'||ans=='Y');
    return(0);
}
