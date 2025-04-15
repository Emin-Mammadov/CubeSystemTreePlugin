// SystemTreePlugin.cpp
#include <CubePlugin.h>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>
#include <QDebug>

class SystemTreePlugin : public cubepluginapi::CubePlugin {
public:
    SystemTreePlugin() : CubePlugin() {}

    virtual void show() override {
        // Try to open the JSON file
        QFile file("system_tree.json");
        if (!file.open(QIODevice::ReadOnly)) {
            qWarning("Couldn't open the JSON file.");
            return;
        }

        // Read and parse the JSON data
        QByteArray jsonData = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
        if (jsonDoc.isNull()) {
            qWarning("Invalid JSON data.");
            return;
        }

        QJsonObject jsonObject = jsonDoc.object();

        // Setup the GUI elements
        QWidget* treeWidgetContainer = new QWidget();
        QVBoxLayout* layout = new QVBoxLayout();
        QTreeWidget* treeWidget = new QTreeWidget();
        treeWidget->setHeaderLabels(QStringList() << "Node Name" << "Description");

        // Populate the tree view using the JSON object
        visualizeSystemTree(jsonObject, treeWidget);

        layout->addWidget(treeWidget);
        treeWidgetContainer->setLayout(layout);

        // Add the container as a new tab in CubeGUI using the defined SYSTEM type
        service->addTab(SYSTEM, treeWidgetContainer);
    }

private:
    // Create the tree widget items from the JSON "nodes" array.
    void visualizeSystemTree(const QJsonObject& jsonObject, QTreeWidget* treeWidget) {
        if (!jsonObject.contains("nodes") || !jsonObject["nodes"].isArray()) {
            qWarning("Invalid system tree structure.");
            return;
        }

        QJsonArray nodes = jsonObject["nodes"].toArray();
        for (const QJsonValue &nodeValue : nodes) {
            QJsonObject node = nodeValue.toObject();
            QTreeWidgetItem* item = new QTreeWidgetItem(treeWidget);
            item->setText(0, node["name"].toString());
            item->setText(1, node["description"].toString());

            if (node.contains("children") && node["children"].isArray()) {
                QJsonArray children = node["children"].toArray();
                addChildrenToItem(children, item);
            }
        }
    }

    // Recursively add child nodes to the given parent item.
    void addChildrenToItem(const QJsonArray& children, QTreeWidgetItem* parentItem) {
        for (const QJsonValue &childValue : children) {
            QJsonObject childNode = childValue.toObject();
            QTreeWidgetItem* childItem = new QTreeWidgetItem(parentItem);
            childItem->setText(0, childNode["name"].toString());
            childItem->setText(1, childNode["description"].toString());

            if (childNode.contains("children") && childNode["children"].isArray()) {
                QJsonArray grandchildren = childNode["children"].toArray();
                addChildrenToItem(grandchildren, childItem);
            }
        }
    }
};

CUBEPLUGIN(SystemTreePlugin)
