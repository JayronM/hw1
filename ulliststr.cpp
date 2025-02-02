#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val){
  
  //if empty
  if(empty()){
    head_ = new Item();
    tail_ = head_;

    head_->first = 0;
    head_->last = 1;
    head_->val[0] = val;
  }
  else if(tail_->last < ARRSIZE){//if there is tail space
    tail_->val[tail_->last] = val;
    tail_->last++;
  }else{ //if fuull
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;
    newItem->prev = tail_;
    tail_-> next= newItem;
    tail_ = newItem;
  }
}

void ULListStr::push_front(const std::string& val){
  if(empty()){
    head_ = new Item();
    tail_ = head_;

    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    head_->val[head_->first] = val;
  }else if (head_->first >0){//room in the front
    head_-> first--;
    head_->val[head_->first]=val;
  } else{//no room
    Item* newItem = new Item();
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->val[newItem->first] = val;
    newItem->next = head_;
    head_->prev= newItem;
    head_ = newItem;
  }
  size_++;
}

void ULListStr::pop_back(){
  tail_->last--;
  size_--;

  if(tail_->first == tail_->last){
    Item* temp = tail_;

    if(head_ == tail_){
      head_= tail_ = nullptr;
    }else{
      tail_ = tail_->prev;
      tail_->next = nullptr;
    }
    delete temp;
  }
}
std::string const & ULListStr::back() const{
  return tail_->val[tail_->last -1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}
std::string* const & ulliststr::getValAtLoc(size_t loc) const{
  if(loc>= size_t){
    return NULL;
  }
  Item* current = head_;
  while(current != nullptr){
    size_t nodSize = current->last - current->first;
    if(loc<nodSize){
      return const_cast<std::string*>(&current->val[current->first + loc]);// pointer to the element
    }
    loc -= nodSize;
    current = current->next;
  }
  return NULL;
}
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
