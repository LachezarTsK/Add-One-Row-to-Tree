
/**
 * @param {TreeNode} root
 * @param {number} val
 * @param {number} depth
 * @return {TreeNode}
 */
var addOneRow = function (root, val, depth) {
    if (depth === 1) {
        let newNode = new TreeNode(val);
        newNode.left = root;
        return newNode;
    }

    const queue = new Queue();
    queue.enqueue(root);
    let currentLevel = 1;

    while (!queue.isEmpty() && currentLevel < depth) {

        let sizeLevel = queue.size();
        while (sizeLevel-- > 0) {
            let current = queue.dequeue();

            if (currentLevel + 1 === depth) {
                let temp = current.left;
                current.left = new TreeNode(val);
                current.left.left = temp;
                queue.enqueue(current.left.left);
            } else if (current.left !== null) {
                queue.enqueue(current.left);
            }

            if (currentLevel + 1 === depth) {
                let temp = current.right;
                current.right = new TreeNode(val);
                current.right.right = temp;
                queue.enqueue(current.right.right);
            } else if (current.right !== null) {
                queue.enqueue(current.right);
            }
        }
        ++currentLevel;
    }
    return root;
};

/*
 Function TreeNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val);
    this.left = (left === undefined ? null : left);
    this.right = (right === undefined ? null : right);
}
