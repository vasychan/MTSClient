// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_TREEVIEW_P_H
#define _GTKMM_TREEVIEW_P_H


#include <gtkmm/private/container_p.h>

#include <glibmm/class.h>

namespace Gtk
{

class TreeView_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef TreeView CppObjectType;
  typedef GtkTreeView BaseObjectType;
  typedef GtkTreeViewClass BaseClassType;
  typedef Gtk::Container_Class CppClassParent;
  typedef GtkContainerClass BaseClassParent;

  friend class TreeView;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void row_activated_callback(GtkTreeView* self, GtkTreePath* p0, GtkTreeViewColumn* p1);
  static gboolean test_expand_row_callback(GtkTreeView* self, GtkTreeIter* p0, GtkTreePath* p1);
  static gboolean test_collapse_row_callback(GtkTreeView* self, GtkTreeIter* p0, GtkTreePath* p1);
  static void row_expanded_callback(GtkTreeView* self, GtkTreeIter* p0, GtkTreePath* p1);
  static void row_collapsed_callback(GtkTreeView* self, GtkTreeIter* p0, GtkTreePath* p1);
  static void cursor_changed_callback(GtkTreeView* self);
  static void columns_changed_callback(GtkTreeView* self);

  //Callbacks (virtual functions):
};


} // namespace Gtk


#endif /* _GTKMM_TREEVIEW_P_H */

