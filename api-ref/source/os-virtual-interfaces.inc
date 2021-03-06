.. -*- rst -*-

=============================================================
 Servers virtual interfaces (servers, os-virtual-interfaces)
=============================================================

Lists virtual interfaces for a server instance.

.. note::
    This API is only implemented for the nova-network service and will result
    in a 400 error response if the cloud is using the Neutron networking
    service. Use the Neutron ``ports`` API to list ports for a given server by
    filtering ports based on the port ``device_id`` which is the
    ``{server_id}``.

List Virtual Interfaces
=======================

.. rest_method:: GET /servers/{server_id}/os-virtual-interfaces

Lists the virtual interfaces for an instance.

Policy defaults enable only users with the administrative role or the owner of
the server to perform this operation. Change these permissions through the
``policy.json`` file.

Normal response codes: 200

Error response codes: badRequest(400), unauthorized(401), forbidden(403), itemNotFound(404)

Request
-------

.. rest_parameters:: parameters.yaml


  - server_id: server_id_path
  - limit: limit_simple
  - offset: offset_simple

Response
--------

.. rest_parameters:: parameters.yaml

  - virtual_interfaces: virtual_interfaces
  - id: virtual_interface_id
  - mac_address: mac_address
  - net_id: net_id_resp_2_12

.. note::

   The API v2 returns the network ID in the "OS-EXT-VIF-NET:net_id" response
   attribute. But API v2.1 base version does not return the network ID.
   Network ID has been added in v2.12 micro-version and returns it in the
   "net_id" attribute.


**Example List Virtual Interfaces: JSON response**

.. literalinclude:: ../../doc/api_samples/os-virtual-interfaces/v2.12/vifs-list-resp.json
   :language: javascript

