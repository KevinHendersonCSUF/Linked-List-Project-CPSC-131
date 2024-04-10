// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Linked-List-Project-CPSC-131.git

#include<iostream>
#include<memory>
#include<vector>
#include<string>

// Write template class Tab here
template<typename T> class Tab {
    public:
    std::shared_ptr<Tab<T>> prev;
    std::shared_ptr<Tab<T>> next;
    std::string url;
    std::string name;
    T memory;
}; // professor said this was good (DONT CHANGE IT)

// Write template class Browser here
template<typename T> class Browser {
   public:
   std::shared_ptr<Tab<T>> head;
   std::shared_ptr<Tab<T>> tail;
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
    }
    else {
        new_tab->url = URL;
        new_tab->name = Name;
        new_tab->memory = Memory;
        tail->next = new_tab;
        tail = new_tab;
        new_tab->next = nullptr;
        
    }
    }
    // int GetSize() { //for me to get the size of the linked list
    // auto curr = head;
    // int counter = 0;
    // while (curr) {
    //     counter++;
    //     curr = curr->next;
    // }
    // return counter;
    // }
   
    void switchToPrevTab() {
       std::shared_ptr<Tab<T>> prev_tab = std::make_shared<Tab<T>>();
       auto curr = head;
        if (curr->next == nullptr) {
            std::cout << "No previous tab" << std::endl << std::endl;
        }
          if (curr->next != nullptr) {
             //make the head the second node, and make the second node the head
             prev_tab = curr->next;
             prev_tab->url = curr->next->url;
             prev_tab->name = curr->next->name;
             prev_tab->memory = curr->next->memory;
             std::cout << prev_tab->url << std::endl << prev_tab->name << std::endl << prev_tab->memory << std::endl << std::endl;
        } //I THINK WORKS NOW
    }

   void switchToNextTab() {
        
       std::shared_ptr<Tab<T>> next_tab = std::make_shared<Tab<T>>();
       auto curr = head;
        if (curr->prev == nullptr) {
            std::cout << "No Next tab" << std::endl << std::endl;
        }
          if (curr->prev != nullptr) {
             //make the head the second node, and make the second node the head
             next_tab = curr->prev;
             next_tab->url = curr->prev->url;
             next_tab->name = curr->prev->name;
             next_tab->memory = curr->prev->memory;
             std::cout << next_tab->url << std::endl << next_tab->name << std::endl << next_tab->memory << std::endl << std::endl;
        } //DOES NOT WORK, BECAUSE CURRENT TAB IS HEAD IDK MANNNN
    }
   void closeCurrentTab() {
    auto curr = head;
    head = head->next;
    std::cout << "Now current tab is = " << head->name << std::endl;
    }
   void bookmarkCurrent() {

    }
   void showBookmarkTab() {

    }
   void moveCurrentToFirst() {
std::shared_ptr<Tab<T>> first = std::make_shared<Tab<T>>();

    first->url = tail->url;
     first->name = tail->name;
      first->memory = tail->memory;
    first->next = head;
    first->prev = nullptr;
    head->prev = first;
    head = first; // GOOD

    // NEED TO FIND A WAY TO DELETE TAIL TAB

    
    }
   T total_memory() {
    auto curr = head;
    T total = 0;
            while(curr){
                total += curr->memory;
                curr = curr->next;
            }
            return total;
    }
   void deleteTab() {
    auto curr = head;
    T most_mem = 0;
    std::string hungry_tab;
            while(curr){
                if (curr->memory > most_mem) {
                    most_mem = curr->memory;
                    hungry_tab = curr->name;
                }
                curr = curr->next;
            }
            //find a way to delete the tab
            std::cout << "deleted element = " << hungry_tab << " with memory size = "<< most_mem << std::endl; //doesnt actually delete the tab yet, although it prints otherwise
   }
//Add display method in Browser template class 
    void display(){
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    
}; // CHANGE DATA TYPE OF EACH FUNCTION IF NEEDED!!!
int main(){
    
    Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    // b1.bookmarkCurrent();
    // b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    // b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    // b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    // b1.bookmarkCurrent();
    b1.display();
    // std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    // b1.showBookmarkTab();
    // b1.moveCurrentToFirst();
    // b1.display();
    // b1.deleteTab();
    // b1.display();
    // std::cout<<"Switch to next tab = "<<std::endl;
    // b1.switchToNextTab();
    // std::cout<<"Switch to previous tab = "<<std::endl;
    // b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.moveCurrentToFirst(); // added this
    // std::cout<<"Switch to previous tab = "<<std::endl;
    // b1.switchToPrevTab();
    // b1.closeCurrentTab();
    b1.display();
    // b1.showBookmarkTab();
    // std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    // b1.deleteTab();
    // b1.display();
    // b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
    // b1.display();
    // std::cout<<"Switch to previous tab = "<<std::endl;
    // b1.switchToPrevTab();
    // std::cout<<"Switch to previous tab = "<<std::endl;
    // b1.switchToPrevTab();
    // std::cout<<"Switch to previous tab = "<<std::endl;
    // b1.switchToPrevTab();
    // b1.bookmarkCurrent();
    // b1.showBookmarkTab();
    // b1.total_memory();
    // b1.deleteTab();
    // b1.display();
    return 0;
}