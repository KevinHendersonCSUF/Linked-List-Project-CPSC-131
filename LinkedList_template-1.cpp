// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Linked-List-Project-CPSC-131.git

#include <iostream>
#include <memory>
#include <string>
#include <utility>  //for pair
#include <vector>

// Write template class Tab here
template <typename T>
class Tab {
 public:
  std::shared_ptr<Tab<T>> prev;
  std::shared_ptr<Tab<T>> next;
  std::string url;
  std::string name;
  T memory;
};

// Write template class Browser here
template <typename T>
class Browser {
 public:
  std::shared_ptr<Tab<T>> head;
  std::shared_ptr<Tab<T>> tail;
  std::vector<std::pair<std::string, std::string>> bookmark;
  void addNewTab(std::string URL, std::string Name, T Memory) {
    std::shared_ptr<Tab<T>> new_tab = std::make_shared<Tab<T>>();
    if (head == nullptr) {
      new_tab->url = URL;
      new_tab->name = Name;
      new_tab->memory = Memory;
      new_tab->next = nullptr;
      new_tab->prev = nullptr;
      head = new_tab;
      tail = new_tab;
    } else {
      new_tab->url = URL;
      new_tab->name = Name;
      new_tab->memory = Memory;
      tail->next = new_tab;
      tail = new_tab;
      new_tab->next = nullptr;
    }
  }
  void switchToPrevTab() {
    std::shared_ptr<Tab<T>> prev_tab = std::make_shared<Tab<T>>();
    auto curr = head;
    if (curr->next == nullptr) {
      std::cout << "No previous tab" << std::endl << std::endl;
    }
    if (curr->next != nullptr) {
      prev_tab = curr;
      prev_tab->url = curr->url;
      prev_tab->name = curr->name;
      prev_tab->memory = curr->memory;
      std::cout << prev_tab->url << std::endl
                << prev_tab->name << std::endl
                << prev_tab->memory << std::endl
                << std::endl;
    }
  }

  void switchToNextTab() {
    std::shared_ptr<Tab<T>> next_tab = std::make_shared<Tab<T>>();
    auto curr = head;
    if (curr->next == nullptr) {
      std::cout << "No Next tab" << std::endl << std::endl;
    }
    if (curr->next != nullptr) {
      next_tab = curr->next;
      next_tab->url = curr->next->url;
      next_tab->name = curr->next->name;
      next_tab->memory = curr->next->memory;
      std::cout << next_tab->url << std::endl
                << next_tab->name << std::endl
                << next_tab->memory << std::endl
                << std::endl;
    }
  }
  void closeCurrentTab() {
    auto curr = head;
    head = head->next;
    std::cout << "Now current tab is = " << head->name << std::endl;
  }
  void bookmarkCurrent() {
    std::pair<std::string, std::string> tab(tail->name, tail->url);
    for (std::pair<std::string, std::string> tab : bookmark) {
      if (tab.first == tail->name) {
        std::cout << "The bookmark is already added!!" << std::endl;
      }
    }
    bookmark.push_back(tab);
  }
  void showBookmarkTab() {
    std::cout << "Bookmarks :" << std::endl;
    for (std::pair<std::string, std::string> bookmarks : bookmark) {
      std::cout << bookmarks.first << "(" << bookmarks.second << ")"
                << std::endl;
    }
  }
  void moveCurrentToFirst() {
    std::shared_ptr<Tab<T>> first = std::make_shared<Tab<T>>();
    std::shared_ptr<Tab<T>> last = std::make_shared<Tab<T>>();
    first->url = tail->url;
    first->name = tail->name;
    first->memory = tail->memory;
    first->next = head;
    first->prev = nullptr;
    head->prev = first;
    head = first;  // GOOD

    // NEED TO FIND A WAY TO DELETE TAIL TAB
    // tail->prev->next = nullptr;
    // tail = tail->prev;
    // ^ IS NOT WORKING FOR SOME REASON.
  }
  T total_memory() {
    auto curr = head;
    T total = 0;
    while (curr) {
      total += curr->memory;
      curr = curr->next;
    }
    return total;
  }
  void deleteTab() {
    auto curr = head;
    T most_mem = 0;
    std::string hungry_tab;
    while (curr) {
      if (curr->memory > most_mem) {
        most_mem = curr->memory;
        hungry_tab = curr->name;
      }
      curr = curr->next;
    }

    // if (curr != head) {
    //   curr = head;
    //   while (curr->name != hungry_tab) {
    //     curr = curr->next;
    //     if (curr->name == hungry_tab) {
    //       curr = head;
    //       head = head->next;
    //       head->prev = nullptr;
    //     }
    //   }

    // }  // THIS DELETES EVERY TAB LEADING UP TO THE MOST POWER HUNGRY ONE, NOT JUST THE POWER HUNGRY ONE
    std::cout << "deleted element = " << hungry_tab
              << " with memory size = " << most_mem
              << std::endl;  // doesnt actually delete the tab yet, although it
                             // prints otherwise
  }
  // Add display method in Browser template class
  void display() {
    auto curr = head;
    std::cout << "Browser tab list = " << std::endl;
    while (curr) {
      std::cout << "| " << curr->name << "  x|-->";
      curr = curr->next;
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }
};
int main() {
  Browser<double> b1;
    b1.addNewTab("https://www.google.com", "Google", 23.45);
    b1.display();
    std::cout << "Switch to previous tab = " << std::endl;
    b1.switchToPrevTab();
    std::cout << "Switch to Next tab = " << std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com", "YouTube", 56);
    b1.bookmarkCurrent();
  b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com", "GeeksForGeeks", 45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com", "ChatGPT", 129);
    b1.addNewTab("https://linkedin.com", "LinkedIn", 410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com", "Github", 110);
    b1.addNewTab("https://kaggle.com", "Kaggle", 310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout << "Total memory consumption = " << b1.total_memory() << "MB"
              << std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
  b1.display();
  b1.deleteTab();
    b1.display();
    std::cout << "Switch to next tab = " << std::endl;
    b1.switchToNextTab();
    std::cout << "Switch to previous tab = " << std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout << "Switch to previous tab = " << std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
  b1.showBookmarkTab();
  std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl; b1.deleteTab(); b1.display();
  b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
  b1.display();
  std::cout<<"Switch to previous tab = "<<std::endl;
  b1.switchToPrevTab();
  std::cout<<"Switch to previous tab = "<<std::endl;
  b1.switchToPrevTab();
  std::cout<<"Switch to previous tab = "<<std::endl;
  b1.switchToPrevTab();
  b1.bookmarkCurrent();
  b1.showBookmarkTab();
  b1.total_memory();
  b1.deleteTab();
  b1.display();
  return 0;
}