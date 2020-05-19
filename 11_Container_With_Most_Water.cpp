class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int area = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                max_area = max_area > area ? max_area : area;
            }
        }
        return max_area;
    }
};


/**
 * Hide Hint:
 * 1. The aim is to maximize the area formed between the vertical lines. 
 *    The area of any container is calculated using the shorter line as length 
 *    and the distance between the lines as the width of the rectangle.
 *          Area = length of shorter vertical line * distance between lines
 *    We can definitely get the maximum width container as the outermost lines 
 *    have the maximum distance between them. However, this container might not 
 *    be the maximum in size as one of the vertical lines of this container could 
 *    be really short. 
 * 2. Start with the maximum width container and go to a shorter width container 
 *    if there is a vertical line longer than the current containers shorter line. 
 *    This way we are compromising on the width but we are looking forward to a 
 *    longer length container.
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, max_area = 0, min_heigh = 0;
        for (int left = 0, right = height.size() - 1; left < right; ) {
            min_heigh = height[left] < height[right] ? height[left++] : height[right--];
            area = (right - left + 1) * min_heigh;
            if (max_area < area)
                max_area = area;
        }
        return max_area;
    }
};

/**
 * Good explanation
 * 1. Start by evaluating the widest container, using the first and the last line. 
 *    All other possible containers are less wide, so to hold more water, they need 
 *    to be higher. Thus, after evaluating that widest container, skip lines at both 
 *    ends that don't support a higher height. Then evaluate that new container we 
 *    arrived at. Repeat until there are no more possible containers left.
*/
