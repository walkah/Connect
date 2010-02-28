<?php
// $Id$

/**
 * @file
 * Views integration for connect module
 */

/**
 * Implementation of hook_views_data.
 */
function connect_views_data() {
  $data = array();

  $data['connect_data']['table']['group'] = t('Connect');

  $data['connect_data']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'pid',
    ),
  );

  $data['connect_data']['pid'] = array(
    'title' => t('Campaign'),
    'help'  => t('The campaign or parent node'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'pid',
      'handler' => 'views_handler_relationship',
      'label' => t('Connect campaign'),
    ),
  );

  return $data;
}