#include <iostream>

class ListItem {
  
  private:

    const char* item;
    ListItem* next = nullptr;
    
  public:
    
    ListItem(const char *newItem) {
      item = newItem;
      next = nullptr;
    }

    ListItem* nextItem() {
      return next;
    }

    void setNextItem(ListItem* new_next) {
      next = new_next;
    }

    const char* view() {
      return item;
    }

};

class LinkedList {

  private:

    ListItem* first_item;
    int list_length;
  
    void deleteItem(ListItem* parent, ListItem* item) {
      parent->setNextItem(item->nextItem());
      delete item;
    }

  public:

    LinkedList(const char *newItem) {
      first_item = new ListItem(newItem);
      list_length = 1;
    }

    void addListItem(const char *newItem) {
      ListItem* new_item = new ListItem(newItem);
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        current_item=next_item;
        next_item = current_item->nextItem();
      }
      current_item->setNextItem(new_item);
      list_length += 1;
    }

  

    int length() {
      return list_length;
    }

    void outputLength() {
      std::cout << length() << std::endl;
    }

    void outputList() {
      std::cout << first_item->view() << std::endl;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        std::cout << next_item->view() << std::endl;
        next_item = next_item->nextItem();
      }
    }

    void deleteListItem(const char *currentItem) {
      ListItem* current_item = new ListItem(currentItem);
     ListItem* next_item = first_item;
      ListItem* current_item = next_item->currentItem();
      while (current_item != nullptr) {
        next_item=current_item;
        current_item = next_item->currentItem();
      }
      next_item->setCurrentItem(current_item);
      list_length -= 1;
    }

    void reverseList() {
      std::cout << current_item->view() << std::endl;
      ListItem* next_item = current_item->nextItem();
      while (next_item != nullptr) {
        std::cout << next_item->view() << std::endl;
        next_item = next_item->nextItem();
      }
    }



};

int main() {
  LinkedList l("sam");
  l.outputList();
  l.outputLength();
  l.addListItem("bob");
  l.outputList();
  l.outputLength();
  l.addListItem("jim");
  l.outputList();
  l.outputLength();
  l.deleteListItem();
  l.outputLength();
}