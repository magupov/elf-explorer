//
// Created by Maxim Agupov on 11.08.2018.
//

#ifndef ELF_EXPLORER_SIMPLELISTMENU_H
#define ELF_EXPLORER_SIMPLELISTMENU_H

#include "Menu.h"
#include <string>
#include <vector>
#include <list>

class ItemContent;

class ListMenuItem {
public:
    ListMenuItem(const std::string &full_label, ItemContent *content);

    std::string getLabel() const {
        return full_label;
    }

    std::string getLabel(size_t size) const {
        if (full_label.size() < size) {
            return full_label.substr(0, size) + std::string (size - full_label.size(), ' ');
        } else if (full_label.size() > size) {
            return full_label.substr(0, size - 1) + '>';
        } else {
            return full_label;
        }
    }

    ItemContent* getContent() {
        return content;
    }

private:
    std::string full_label;
    ItemContent *content;
};

class ListMenu : public Menu {
public:
    ListMenu(int width, int height, int startx, int starty);
    virtual ~ListMenu();

    void render();

    bool run();

    void handleUp();
    void handleDown();

    void addItem(const std::string &label, ItemContent *item);
    ItemContent *getChosenItem();

private:
    std::list<ListMenuItem*> full_list;
    std::list<ListMenuItem*>::iterator chosen_item;

    int first_visible_item;
    int visible_size;
    int highlighted;

};


#endif //ELF_EXPLORER_SIMPLELISTMENU_H
