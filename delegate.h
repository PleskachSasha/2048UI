#ifndef DELEGATE_H
#define DELEGATE_H
#include <QStyledItemDelegate>
#include <QLabel>
#include <QModelIndex>
#include <QPainter>
#include <QStyleOptionViewItem>

class Delegate : public QStyledItemDelegate {
public:
    Delegate();
    Delegate(int initialValue);

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override {
        QLabel* editor = new QLabel(parent);

        if (value == 2){
            editor->setStyleSheet("background-color: red;");
        }
        if (value == 4){
            editor->setStyleSheet("background-color: blue;");
        }
        if (value == 8){
            editor->setStyleSheet("background-color: green;");
        }
        if (value == 16){
            editor->setStyleSheet("background-color: yellow;");
        }
    }

    QVariant getValue() const {
        return value;
    }

    bool operator!=(const int& other) const {
        return this->value != other;
    }
    bool operator!=(const Delegate& other) const {
        return this->value != other.value;
    }
    bool operator==(const Delegate& other) const {
        return this->value == other.value;
    }
    Delegate operator*(const Delegate& other) const {
        int resultValue = this->value.toInt() * other.value.toInt();
        return Delegate(resultValue);
    }
    Delegate& operator=(const Delegate& other) {
        if (this != &other) {
            this->value = other.value;
        }
        return *this;
    }
private:
    QVariant  value;
};

#endif // DELEGATE_H
