/* 尝试用非递归方式写分治 */


/* 分治递归（in-place 是指调整指针的指向） */
// 先调整位置，再插入
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return ;
        }

        // 分治(完成之后，他们都是单链表)
        flatten(root->left);
        flatten(root->right);

        // merge（先处理掉子树之间的关系，再插入）
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        TreeNode *end = root;    // the end of new sub-right-child-tree
        while (end->right != nullptr) {
            end = end->right;
        }

        end->right = tmp;
    }
};

// 先插入，再调整位置
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return ;
        }

        // 分治(完成之后，他们都是单链表)
        flatten(root->left);
        flatten(root->right);

        // 左边是 nullptr 就意味着：不需要改变子树
        TreeNode *insert = root->left;
        if (insert != nullptr) {
            while (insert->right != nullptr) {
                insert = insert->right;
            }
            insert->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};


/* 直接接插 */
// 根据先序遍历的特点，将右节点不断插入到左子树中最右边的节点下
// 这样就确保了：总是先遇到左节点（先序嘛，不管三七二十一，先把左子树放到右边）
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left == nullptr) {
                root = root->right;

            } else {
                TreeNode *insert = root->left;
                while (insert->right != nullptr) {
                    insert = insert->right;
                }

                insert->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
        }

    }
};