
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode newNode = new TreeNode(val);
            newNode.left = root;
            return newNode;
        }

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int currentLevel = 1;

        while (!queue.isEmpty() && currentLevel < depth) {

            int sizeLevel = queue.size();
            while (sizeLevel-- > 0) {
                TreeNode current = queue.poll();

                if (currentLevel + 1 == depth) {
                    TreeNode temp = current.left;
                    current.left = new TreeNode(val);
                    current.left.left = temp;
                    queue.add(current.left.left);
                } else if (current.left != null) {
                    queue.add(current.left);
                }

                if (currentLevel + 1 == depth) {
                    TreeNode temp = current.right;
                    current.right = new TreeNode(val);
                    current.right.right = temp;
                    queue.add(current.right.right);
                } else if (current.right != null) {
                    queue.add(current.right);
                }
            }
            ++currentLevel;
        }
        return root;
    }
}

/*
Class TreeNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class TreeNode {

    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(){}

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
