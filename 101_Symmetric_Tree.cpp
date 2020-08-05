// not mine    DFS
// 判断两个指针当前节点值是否相等
// 判断 A 的右子树与 B 的左子树是否对称
// 判断 A 的左子树与 B 的右子树是否对称
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    public boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.val == t2.val)
            && isMirror(t1.right, t2.left)
            && isMirror(t1.left, t2.right);
    }
}


/* BFS(not mine) */
class Solution {
	public boolean isSymmetric(TreeNode root) {
		if(root==null || (root.left==null && root.right==null)) {
			return true;
		}
		//用队列保存节点
		LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
		//将根节点的左右孩子放到队列中
		queue.add(root.left);
		queue.add(root.right);
		while(queue.size()>0) {
			//从队列中取出两个节点，再比较这两个节点
			TreeNode left = queue.removeFirst();
			TreeNode right = queue.removeFirst();
			//如果两个节点都为空就继续循环，两者有一个为空就返回false
			if(left==null && right==null) {
				continue;
			}
			if(left==null || right==null) {
				return false;
			}
			if(left.val!=right.val) {
				return false;
			}
			//将左节点的左孩子， 右节点的右孩子放入队列
			queue.add(left.left);
			queue.add(right.right);
			//将左节点的右孩子，右节点的左孩子放入队列
			queue.add(left.right);
			queue.add(right.left);
		}
		
		return true;
	}
}



/* BFS Version(十分慢，而且不优雅) */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }        


        vector<TreeNode *> level;
        level.emplace_back(root); 

        while (level.size() != 0) {
            int left = 0, right = level.size() - 1;

            while (left < right) {
                if (level[left] == level[right] && level[left] == nullptr) {
                    left++;
                    right--;
                    continue;

                } else if (level[left] == nullptr || level[right] == nullptr) {
                    return false;

                } else if (level[left]->val != level[right]->val) {
                    return false;
                }
                left++;
                right--;
            }

            vector<TreeNode *> tmp;
            for (TreeNode *node : level) {
                if (node != nullptr) {
                    tmp.emplace_back(node->left);
                    tmp.emplace_back(node->right);
                }
            }

            level.swap(tmp);
        }

        return true;
    }
};
