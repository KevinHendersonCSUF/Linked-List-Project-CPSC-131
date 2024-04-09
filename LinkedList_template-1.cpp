// Name: Kevin Henderson
// CWID: 885395855
// Git repository Link:
// https://github.com/KevinHendersonCSUF/Linked-List-Project-CPSC-131.git

#include<iostream>
#include<memory>
#include<vector>
#include<string>

// template<typename T> class Node { FOR REFERENCE
//     public:
//     Node(std::shared_ptr<Node> prev, T data, std::shared_ptr<Node> next) : prev_(prev), data_(data), next_(next) {}
//     private:
//     std::shared_ptr<Node> prev_, next_;
//     T data_;
// };
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
        new_tab->next = nullptr; //unsure, professor said it was good but idk
        
    }
    }
    void switchToPrevTab() {
        std::cout << "Switch to previous tab = " << tail->prev->url << std::endl << tail->prev->name
                                                 << std::endl << tail->prev->memory << std::endl;
        if (tail->prev == nullptr) {
            std::cout << "No previous tab" << std::endl;
        }
    } //unsure

   void switchToNextTab() {

    }
   void closeCurrentTab() {

    }
   void bookmarkCurrent() {

    }
   void showBookmarkTab() {

    }
   void moveCurrentToFirst() {

    }
   void total_memory() {

    }
   void deleteTab() {

    }
//Add display method in Browser template class 
    /*void display(){
            auto curr = head;
            std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
                std::cout<<"| "<<curr->name<<"  x|-->";
                curr = curr->next;
            }
            std::cout<<std::endl;
            std::cout<<std::endl;
        }
    */
}; // CHANGE DATA TYPE OF EACH FUNCTION IF NEEDED!!!
int main(){
    
    /*Browser<double> b1;
    b1.addNewTab("https://www.google.com","Google",23.45);
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    std::cout<<"Switch to Next tab = "<<std::endl;
    b1.switchToNextTab();
    b1.addNewTab("https://www.youtube.com","YouTube",56);
    b1.bookmarkCurrent();
    b1.display();
    b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
    b1.bookmarkCurrent();
    b1.addNewTab("https://chat.openai.com","ChatGPT",129);
    b1.addNewTab("https://linkedin.com","LinkedIn",410);
    b1.bookmarkCurrent();
    b1.addNewTab("https://github.com","Github",110);
    b1.addNewTab("https://kaggle.com","Kaggle",310);
    b1.bookmarkCurrent();
    b1.display();
    std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.showBookmarkTab();
    b1.moveCurrentToFirst();
    b1.display();
    b1.deleteTab();
    b1.display();
    std::cout<<"Switch to next tab = "<<std::endl;
    b1.switchToNextTab();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    std::cout<<"Switch to previous tab = "<<std::endl;
    b1.switchToPrevTab();
    b1.closeCurrentTab();
    b1.display();
    b1.showBookmarkTab();
    std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
    b1.deleteTab();
    b1.display();
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
    b1.display();*/
    return 0;
}