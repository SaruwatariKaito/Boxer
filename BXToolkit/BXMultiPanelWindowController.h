/* 
 Boxer is copyright 2010 Alun Bestor and contributors.
 Boxer is released under the GNU General Public License 2.0. A full copy of this license can be
 found in this XCode project at Resources/English.lproj/GNU General Public License.txt, or read
 online at [http://www.gnu.org/licenses/gpl-2.0.txt].
 */


//BXMultiPanelWindowController is an NSWindowController subclass for managing windows that display
//one out of a set of panels: e.g. a tabbed preferences window or a wizard. This class provides
//methods for changing the current panel and animating transitions from one panel to another
//(resizing the window and crossfading views).

#import <Cocoa/Cocoa.h>

@interface BXMultiPanelWindowController : NSWindowController
{
	IBOutlet NSView *panelContainer;
}

#pragma mark -
#pragma mark Properties
@property (assign, nonatomic) NSView *currentPanel;	//The currently-displayed panel.

//The view into which the current panel will be added.
@property (retain, nonatomic) NSView *panelContainer;	


#pragma mark Animation methods

//Returns an animation that will fade out oldPanel to reveal newPanel. This is mainly suited for opaque panels.
- (NSViewAnimation *) fadeOutPanel: (NSView *)oldPanel overPanel: (NSView *)newPanel;

//Returns an animation that instantly hides oldPanel then fades in newPanel. Suited for transparent panels.
- (NSViewAnimation *) hidePanel: (NSView *)oldPanel andFadeInPanel: (NSView *)newPanel;

//Returns the NSAnimation which will perform the transition from one panel to the other.
//Intended to be overridden by subclasses to define their own animations.
//Defaults to returning hidePanel:andFadeInPanel: with a duration of 0.25.
- (NSViewAnimation *) transitionFromPanel: (NSView *)oldPanel toPanel: (NSView *)newPanel;

@end