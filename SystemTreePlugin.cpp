// SystemTreePlugin.cpp
#include <CubePlugin.h>
#include <Cube.h>
#include <CubeSystemTreeNode.h>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>

class SystemTreePlugin : public cubepluginapi::CubePlugin {
public:
    SystemTreePlugin() : CubePlugin() {}

    virtual void show() override {
        cube::Cube* cube = getCube();  // Get the active .cubex cube handle
        if (!cube) {
            qWarning("No cube data available.");
            return;
        }

        const std::vector<cube::SystemTreeNode*>& roots = cube->getSystemTree();  // Root system nodes
        QJsonArray jsonTree = convertSystemTreeToJson(roots);
        QJsonObject wrappedJson;
        wrappedJson["nodes"] = jsonTree;
        QJsonDocument doc(wrappedJson);
        QString prettyJson = doc.toJson(QJsonDocument::Indented);

        // Create scrollable widget to show JSON
        QTextEdit* jsonView = new QTextEdit();
        jsonView->setText(prettyJson);
        jsonView->setReadOnly(true);

        QWidget* container = new QWidget();
        QVBoxLayout* layout = new QVBoxLayout();
        layout->addWidget(jsonView);
        container->setLayout(layout);

        service->addTab(SYSTEM, container);  // SYSTEM tab for system tree
    }

private:
    QJsonArray convertSystemTreeToJson(const std::vector<cube::SystemTreeNode*>& nodes) {
        QJsonArray jsonArray;
        for (const cube::SystemTreeNode* node : nodes) {
            QJsonObject obj;
            obj["name"] = QString::fromStdString(node->getName());
            obj["type"] = QString::fromStdString(node->getTypeAsString());
            obj["id"] = static_cast<int>(node->getId());

            const std::vector<cube::SystemTreeNode*>& children = node->getChildren();
            if (!children.empty()) {
                obj["children"] = convertSystemTreeToJson(children);
            }

            jsonArray.append(obj);
        }
        return jsonArray;
    }
};

CUBEPLUGIN(SystemTreePlugin)
